// The eight environments below are v0.14's own artwork, lifted out of that
// ROM in the compressed form the game already reads. v0.14 was built from a
// tree that was never committed, so its .png sources do not exist -- the
// stock ones are still beside these files, unused, rather than deleted.
const u32 gBattleEnvironmentTiles_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_TallGrass[] = INCGFX_U16("graphics/battle_environment/tall_grass/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_LongGrass[] = INCGFX_U16("graphics/battle_environment/long_grass/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_Sand[] = INCBIN_U32("graphics/battle_environment/sand/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_Sand[] = INCGFX_U16("graphics/battle_environment/sand/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Sand[] = INCBIN_U32("graphics/battle_environment/sand/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_Underwater[] = INCGFX_U16("graphics/battle_environment/underwater/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_Water[] = INCBIN_U32("graphics/battle_environment/water/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_Water[] = INCGFX_U16("graphics/battle_environment/water/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Water[] = INCBIN_U32("graphics/battle_environment/water/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_PondWater[] = INCGFX_U16("graphics/battle_environment/pond_water/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_Rock[] = INCBIN_U32("graphics/battle_environment/rock/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_Rock[] = INCGFX_U16("graphics/battle_environment/rock/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Rock[] = INCBIN_U32("graphics/battle_environment/rock/v014_bg_map.bin");

const u32 gBattleEnvironmentTiles_Cave[] = INCGFX_U32("graphics/battle_environment/cave/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Cave[] = INCGFX_U16("graphics/battle_environment/cave/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Cave[] = INCGFX_U32("graphics/battle_environment/cave/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Building[] = INCBIN_U32("graphics/battle_environment/building/v014_bg_tiles.bin");
const u16 gBattleEnvironmentPalette_Building[] = INCGFX_U16("graphics/battle_environment/building/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Building[] = INCBIN_U32("graphics/battle_environment/building/v014_bg_map.bin");

const u16 gBattleEnvironmentPalette_BuildingGym[] = INCGFX_U16("graphics/battle_environment/building/gym.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_BuildingLeader[] = INCGFX_U16("graphics/battle_environment/building/leader.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_Plain[] = INCGFX_U16("graphics/battle_environment/plain/palette.pal", ".gbapal");

const u32 gBattleEnvironmentTiles_Stadium[] = INCGFX_U32("graphics/battle_environment/stadium/tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentTilemap_Stadium[] = INCGFX_U32("graphics/battle_environment/stadium/map.bin", ".smolTM");

const u16 gBattleEnvironmentPalette_Frontier[] = INCGFX_U16("graphics/battle_environment/stadium/battle_frontier.pal", ".gbapal"); // this is also used for link battles
const u16 gBattleEnvironmentPalette_StadiumAqua[] = INCGFX_U16("graphics/battle_environment/stadium/aqua.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumMagma[] = INCGFX_U16("graphics/battle_environment/stadium/magma.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumSidney[] = INCGFX_U16("graphics/battle_environment/stadium/sidney.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumPhoebe[] = INCGFX_U16("graphics/battle_environment/stadium/phoebe.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumGlacia[] = INCGFX_U16("graphics/battle_environment/stadium/glacia.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumDrake[] = INCGFX_U16("graphics/battle_environment/stadium/drake.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_StadiumWallace[] = INCGFX_U16("graphics/battle_environment/stadium/wallace.pal", ".gbapal");

const u16 gBattleEnvironmentPalette_Kyogre[] = INCGFX_U16("graphics/battle_environment/water/kyogre.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_Groudon[] = INCGFX_U16("graphics/battle_environment/cave/groudon.pal", ".gbapal");

const u32 gBattleEnvironmentTiles_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Rayquaza[] = INCGFX_U16("graphics/battle_environment/sky/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Sand[] = INCBIN_U32("graphics/battle_environment/sand/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_Sand[] = INCBIN_U32("graphics/battle_environment/sand/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Water[] = INCBIN_U32("graphics/battle_environment/water/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_Water[] = INCBIN_U32("graphics/battle_environment/water/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Rock[] = INCBIN_U32("graphics/battle_environment/rock/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_Rock[] = INCBIN_U32("graphics/battle_environment/rock/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Cave[] = INCGFX_U32("graphics/battle_environment/cave/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Cave[] = INCGFX_U32("graphics/battle_environment/cave/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Building[] = INCBIN_U32("graphics/battle_environment/building/v014_entry_tiles.bin");
const u32 gBattleEnvironmentAnimTilemap_Building[] = INCBIN_U32("graphics/battle_environment/building/v014_entry_map.bin");

const u32 gBattleEnvironmentAnimTiles_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/anim_map.bin", ".smolTM");
