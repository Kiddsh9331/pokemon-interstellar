# Pokémon Interstellar

[![Build](https://github.com/Kiddsh9331/pokemon-interstellar/actions/workflows/interstellar.yml/badge.svg?branch=interstellar)](https://github.com/Kiddsh9331/pokemon-interstellar/actions/workflows/interstellar.yml)

A GBA ROM hack built on [RHH's `pokeemerald-expansion`](https://github.com/rh-hideout/pokeemerald-expansion):
an Emerald spin-off story with a FireRed look, played across four fractured regions.

A wounded Deoxys crash-lands and shatters time. Kanto, Hoenn, Johto and Sinnoh fuse into one broken
timeline, and in the deepest scar of each region a legendary Pokémon is held as a **corrupted anchor**.
You cross the rifts, take two gyms and one anchor per region, and try to put the sky back together.

**There are no villains.** Every boss is a patient. Every anchor can be **caught** as well as beaten,
and a caught anchor sleeps in the Rift Vault until the postgame opens it.

## Status

| Act | Region | Content |
|---|---|---|
| 1 | Kanto | Playable — prologue, Pewter and Cerulean gyms, Mt. Moon, Corrupted Mewtwo, crossing to Hoenn |
| 2 | Hoenn | Playable — Slateport, Mauville and Lavaridge gyms, Mt. Chimney, Corrupted Rayquaza, Act 2 ending |
| 3–5 | Johto, Sinnoh, finale | Not started |

Both acts are demo-complete and end with a card telling you where the story stops.

## Building

The build runs on Linux or WSL. You do **not** need a base ROM: the whole game is compiled from source.

```bash
sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi libpng-dev python3
git clone https://github.com/Kiddsh9331/pokemon-interstellar.git
cd pokemon-interstellar
git checkout -- src/data/heal_locations.json   # see the note below
make firered -j$(nproc)                        # -> pokefirered.gba, the hack
```

`make firered` is the hack. `make` (the Emerald target) still compiles but is not the game.

**Always run `git checkout -- src/data/heal_locations.json` before building.** The map tooling
rewrites that file in place for whichever target is building, so the two targets overwrite each
other's entries. If a build fails with a `JSONPROC_ERROR`, restore the file and build again.

For everything else about the engine, see [`README-rhh.md`](README-rhh.md) and [`INSTALL.md`](INSTALL.md).

## Playing a demo

**No ROMs are distributed here, and none are ever committed to this repository.** A built `.gba`
is a complete Pokémon game and is not ours to hand out. Demos are shared as **BPS patches**, which
you apply to a Pokémon FireRed (U) 1.0 ROM that you own:

1. Download the `.bps` from [Releases](../../releases).
2. Apply it to your own FireRed ROM with [Floating IPS](https://www.smwcentral.net/?p=section&a=details&id=11474),
   [Rom Patcher JS](https://www.marcrobledo.com/RomPatcher.js/) or any BPS patcher.
3. Play the result in [mGBA](https://mgba.io).

Or just build from source with the steps above.

### Making a patch (maintainers)

```bash
python3 tools/interstellar/makepatch.py baserom_firered.gba pokefirered.gba interstellar-v0.99b.bps
```

The tool verifies its own output by applying the patch back and comparing checksums, so a patch that
prints `OK` is known to reconstruct the ROM exactly. `baserom_firered.gba` is gitignored.

## Credits

Interstellar stands on other people's work. See [`CREDITS-INTERSTELLAR.md`](CREDITS-INTERSTELLAR.md)
for the full list, and [`CREDITS.md`](CREDITS.md) for the expansion's own contributors.

Based on RHH's `pokeemerald-expansion` 1.16.3 — https://github.com/rh-hideout/pokeemerald-expansion/
