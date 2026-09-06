#!/usr/bin/env python3
"""Build a BPS patch so a demo can be shared without handing out a ROM.

    python3 tools/interstellar/makepatch.py <base.gba> <built.gba> <out.bps>

The recipient applies the patch to a ROM they already own. The patch is verified before it is
written: this script applies its own output to the base and compares the result byte for byte
with the built ROM, so a run that prints OK cannot produce a broken download.

Self-test (no ROMs needed):  python3 makepatch.py --selftest
"""
import sys, zlib
from array import array

# ---------------------------------------------------------------- number format
def num(n):
    """BPS variable-length number."""
    out = bytearray()
    while True:
        x = n & 0x7F
        n >>= 7
        if n == 0:
            out.append(0x80 | x)
            return bytes(out)
        out.append(x)
        n -= 1

def read_num(data, pos):
    result, shift = 0, 0
    while True:
        b = data[pos]; pos += 1
        result += (b & 0x7F) << shift
        if b & 0x80:
            return result, pos
        shift += 7
        result += 1 << shift

def signed(n):
    return num((abs(n) << 1) | (1 if n < 0 else 0))

SOURCE_READ, TARGET_READ, SOURCE_COPY, TARGET_COPY = 0, 1, 2, 3
HASH_BITS = 22                     # 4M slots: enough for a 32 MB ROM, ~16 MB of RAM
HASH_MASK = (1 << HASH_BITS) - 1
MIN_MATCH = 8

def encode(source, target):
    """SourceRead for aligned runs, SourceCopy for moved data, TargetCopy for byte runs,
    TargetRead for anything left. Every action is valid BPS; the applier verifies the result."""
    slen, tlen = len(source), len(target)
    # last position of each 4-byte key in the source
    table = array("l", [-1]) * (1 << HASH_BITS)
    for i in range(slen - 4):
        key = (source[i] | (source[i+1] << 8) | (source[i+2] << 16) | (source[i+3] << 24))
        table[(key * 0x9E3779B1 >> 8) & HASH_MASK] = i

    out = bytearray(b"BPS1")
    out += num(slen) + num(tlen) + num(0)
    literals = bytearray()
    src_rel = tgt_rel = 0
    o = 0
    def flush():
        nonlocal literals
        if literals:
            out.extend(num(((len(literals) - 1) << 2) | TARGET_READ))
            out.extend(literals)
            literals = bytearray()
    while o < tlen:
        # 1. same byte at the same offset in the base
        n = 0
        while o + n < tlen and o + n < slen and source[o + n] == target[o + n]:
            n += 1
        best, kind, at = n, SOURCE_READ, 0
        # 2. the same bytes somewhere else in the base
        if o + 4 <= tlen:
            key = (target[o] | (target[o+1] << 8) | (target[o+2] << 16) | (target[o+3] << 24))
            cand = table[(key * 0x9E3779B1 >> 8) & HASH_MASK]
            if cand >= 0:
                m = 0
                while o + m < tlen and cand + m < slen and source[cand + m] == target[o + m]:
                    m += 1
                if m > best and m >= MIN_MATCH:
                    best, kind, at = m, SOURCE_COPY, cand
        # 3. a run of the byte we just wrote (padding, blank tiles)
        if o > 0:
            m = 0
            while o + m < tlen and target[o + m] == target[o - 1]:
                m += 1
            if m > best and m >= MIN_MATCH:
                best, kind, at = m, TARGET_COPY, o - 1
        if best >= MIN_MATCH or (kind == SOURCE_READ and best >= 4):
            flush()
            if kind == SOURCE_READ:
                out.extend(num(((best - 1) << 2) | SOURCE_READ))
            elif kind == SOURCE_COPY:
                out.extend(num(((best - 1) << 2) | SOURCE_COPY)); out.extend(signed(at - src_rel)); src_rel = at + best
            else:
                out.extend(num(((best - 1) << 2) | TARGET_COPY)); out.extend(signed(at - tgt_rel)); tgt_rel = at + best
            o += best
        else:
            literals.append(target[o]); o += 1
    flush()
    out += zlib.crc32(source).to_bytes(4, "little")
    out += zlib.crc32(target).to_bytes(4, "little")
    out += zlib.crc32(bytes(out)).to_bytes(4, "little")
    return bytes(out)

def apply(patch, source):
    """Minimal BPS applier, used to verify what we just produced."""
    if patch[:4] != b"BPS1":
        raise ValueError("not a BPS patch")
    if zlib.crc32(patch[:-4]) != int.from_bytes(patch[-4:], "little"):
        raise ValueError("patch checksum mismatch")
    pos = 4
    slen, pos = read_num(patch, pos)
    tlen, pos = read_num(patch, pos)
    mlen, pos = read_num(patch, pos); pos += mlen
    if slen != len(source):
        raise ValueError("base ROM is %d bytes, patch expects %d" % (len(source), slen))
    if zlib.crc32(source) != int.from_bytes(patch[-12:-8], "little"):
        raise ValueError("base ROM checksum mismatch")
    target = bytearray(tlen)
    o = src_rel = tgt_rel = 0
    end = len(patch) - 12
    while pos < end:
        data, pos = read_num(patch, pos)
        action, length = data & 3, (data >> 2) + 1
        if action == SOURCE_READ:
            target[o:o + length] = source[o:o + length]; o += length
        elif action == TARGET_READ:
            target[o:o + length] = patch[pos:pos + length]; pos += length; o += length
        else:
            off, pos = read_num(patch, pos)
            off = (off >> 1) * (-1 if off & 1 else 1)
            if action == SOURCE_COPY:
                src_rel += off
                target[o:o + length] = source[src_rel:src_rel + length]; src_rel += length; o += length
            else:
                tgt_rel += off
                for _ in range(length):            # overlapping copies are legal and expected
                    target[o] = target[tgt_rel]; o += 1; tgt_rel += 1
    if zlib.crc32(bytes(target)) != int.from_bytes(patch[-8:-4], "little"):
        raise ValueError("patched output checksum mismatch")
    return bytes(target)

def selftest():
    import random
    rnd = random.Random(7)
    src = bytearray(rnd.randbytes(400000))
    tgt = bytearray(src)
    tgt[1000:1000] = b"interstellar"          # insertion shifts everything after it
    tgt[50000:50100] = rnd.randbytes(100)     # a rewritten block
    tgt += b"\xff" * 60000                    # padding run
    tgt += src[200000:260000]                 # a block moved in from elsewhere
    p = encode(bytes(src), bytes(tgt))
    got = apply(p, bytes(src))
    assert got == bytes(tgt), "round trip mismatch"
    print("selftest OK  base %d  target %d  patch %d bytes (%.1f%% of target)"
          % (len(src), len(tgt), len(p), 100.0 * len(p) / len(tgt)))

def main():
    if "--selftest" in sys.argv:
        selftest(); return 0
    if len(sys.argv) != 4:
        print(__doc__); return 2
    base_path, built_path, out_path = sys.argv[1:4]
    base = open(base_path, "rb").read()
    built = open(built_path, "rb").read()
    print("base  %s  %d bytes" % (base_path, len(base)))
    print("built %s  %d bytes" % (built_path, len(built)))
    patch = encode(base, built)
    print("verifying...")
    if apply(patch, base) != built:
        print("FAILED: the patch does not reconstruct the ROM; nothing written"); return 1
    open(out_path, "wb").write(patch)
    print("OK  wrote %s  %.1f MB" % (out_path, len(patch) / 1048576.0))
    return 0

if __name__ == "__main__":
    sys.exit(main())
