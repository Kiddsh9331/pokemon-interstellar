const u32 gBattleEnvironmentTiles_TallGrass[] = INCGFX_U32("graphics/battle_environment/hns_tall_grass/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_TallGrass[] = INCGFX_U16("graphics/battle_environment/hns_tall_grass/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_TallGrass[] = INCGFX_U32("graphics/battle_environment/hns_tall_grass/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_LongGrass[] = INCGFX_U32("graphics/battle_environment/hns_long_grass/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_LongGrass[] = INCGFX_U16("graphics/battle_environment/hns_long_grass/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_LongGrass[] = INCGFX_U32("graphics/battle_environment/hns_long_grass/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Sand[] = INCGFX_U32("graphics/battle_environment/hns_sand/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Sand[] = INCGFX_U16("graphics/battle_environment/hns_sand/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Sand[] = INCGFX_U32("graphics/battle_environment/hns_sand/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Underwater[] = INCGFX_U32("graphics/battle_environment/underwater/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Underwater[] = INCGFX_U16("graphics/battle_environment/underwater/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Underwater[] = INCGFX_U32("graphics/battle_environment/underwater/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Water[] = INCGFX_U32("graphics/battle_environment/hns_water/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Water[] = INCGFX_U16("graphics/battle_environment/hns_water/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Water[] = INCGFX_U32("graphics/battle_environment/hns_water/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_PondWater[] = INCGFX_U32("graphics/battle_environment/hns_pond_water/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_PondWater[] = INCGFX_U16("graphics/battle_environment/hns_pond_water/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_PondWater[] = INCGFX_U32("graphics/battle_environment/hns_pond_water/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Rock[] = INCGFX_U32("graphics/battle_environment/hns_rock/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Rock[] = INCGFX_U16("graphics/battle_environment/hns_rock/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Rock[] = INCGFX_U32("graphics/battle_environment/hns_rock/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Cave[] = INCGFX_U32("graphics/battle_environment/hns_cave/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Cave[] = INCGFX_U16("graphics/battle_environment/hns_cave/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Cave[] = INCGFX_U32("graphics/battle_environment/hns_cave/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Building[] = INCGFX_U32("graphics/battle_environment/building/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Building[] = INCGFX_U16("graphics/battle_environment/building/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Building[] = INCGFX_U32("graphics/battle_environment/building/map.bin", ".smolTM");

// Indoor trainers, outdoor trainers, gym trainers and leaders all shared
// Building's tiles and were told apart by palette alone. The Battle Backgrounds
// Patch draws each of them separately, so they get their own art now.
const u32 gBattleEnvironmentTiles_Plain[] = INCGFX_U32("graphics/battle_environment/plain/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Plain[] = INCGFX_U16("graphics/battle_environment/plain/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Plain[] = INCGFX_U32("graphics/battle_environment/plain/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Gym[] = INCGFX_U32("graphics/battle_environment/gym/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_BuildingGym[] = INCGFX_U16("graphics/battle_environment/gym/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Gym[] = INCGFX_U32("graphics/battle_environment/gym/map.bin", ".smolTM");

const u32 gBattleEnvironmentTiles_Leader[] = INCGFX_U32("graphics/battle_environment/leader/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_BuildingLeader[] = INCGFX_U16("graphics/battle_environment/leader/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Leader[] = INCGFX_U32("graphics/battle_environment/leader/map.bin", ".smolTM");

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

const u16 gBattleEnvironmentPalette_Kyogre[] = INCGFX_U16("graphics/battle_environment/hns_water/kyogre.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_Groudon[] = INCGFX_U16("graphics/battle_environment/hns_cave/groudon.pal", ".gbapal");

const u32 gBattleEnvironmentTiles_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Rayquaza[] = INCGFX_U16("graphics/battle_environment/sky/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_TallGrass[] = INCGFX_U32("graphics/battle_environment/hns_tall_grass/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_TallGrass[] = INCGFX_U32("graphics/battle_environment/hns_tall_grass/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_LongGrass[] = INCGFX_U32("graphics/battle_environment/hns_long_grass/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_LongGrass[] = INCGFX_U32("graphics/battle_environment/hns_long_grass/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Sand[] = INCGFX_U32("graphics/battle_environment/hns_sand/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Sand[] = INCGFX_U32("graphics/battle_environment/hns_sand/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Underwater[] = INCGFX_U32("graphics/battle_environment/underwater/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Underwater[] = INCGFX_U32("graphics/battle_environment/underwater/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Water[] = INCGFX_U32("graphics/battle_environment/hns_water/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Water[] = INCGFX_U32("graphics/battle_environment/hns_water/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_PondWater[] = INCGFX_U32("graphics/battle_environment/hns_pond_water/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_PondWater[] = INCGFX_U32("graphics/battle_environment/hns_pond_water/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Rock[] = INCGFX_U32("graphics/battle_environment/hns_rock/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Rock[] = INCGFX_U32("graphics/battle_environment/hns_rock/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Cave[] = INCGFX_U32("graphics/battle_environment/hns_cave/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Cave[] = INCGFX_U32("graphics/battle_environment/hns_cave/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Building[] = INCGFX_U32("graphics/battle_environment/building/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Building[] = INCGFX_U32("graphics/battle_environment/building/anim_map.bin", ".smolTM");

const u32 gBattleEnvironmentAnimTiles_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Rayquaza[] = INCGFX_U32("graphics/battle_environment/sky/anim_map.bin", ".smolTM");

// Heart & Soul volcano cave (battlebg port) -- BATTLE_ENVIRONMENT_VOLCANO, used in FIERY PATH
const u32 gBattleEnvironmentTiles_Volcano[] = INCGFX_U32("graphics/battle_environment/hns_volcano/tiles.png", ".4bpp.smol");
const u16 gBattleEnvironmentPalette_Volcano[] = INCGFX_U16("graphics/battle_environment/hns_volcano/palette.pal", ".gbapal");
const u32 gBattleEnvironmentTilemap_Volcano[] = INCGFX_U32("graphics/battle_environment/hns_volcano/map.bin", ".smolTM");
const u32 gBattleEnvironmentAnimTiles_Volcano[] = INCGFX_U32("graphics/battle_environment/hns_volcano/anim_tiles.png", ".4bpp.smol");
const u32 gBattleEnvironmentAnimTilemap_Volcano[] = INCGFX_U32("graphics/battle_environment/hns_volcano/anim_map.bin", ".smolTM");

// Heart & Soul time-of-day battle palettes (battlebg port, apply.py --tod)
const u16 gBattleEnvironmentPalette_TallGrassTwilight[] = INCGFX_U16("graphics/battle_environment/hns_tall_grass/palette_morning.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_TallGrassNight[] = INCGFX_U16("graphics/battle_environment/hns_tall_grass/palette_night.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_LongGrassNight[] = INCGFX_U16("graphics/battle_environment/hns_long_grass/palette_night.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_SandTwilight[] = INCGFX_U16("graphics/battle_environment/hns_sand/palette_morning.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_SandNight[] = INCGFX_U16("graphics/battle_environment/hns_sand/palette_night.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_WaterTwilight[] = INCGFX_U16("graphics/battle_environment/hns_water/palette_morning.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_WaterNight[] = INCGFX_U16("graphics/battle_environment/hns_water/palette_night.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_PondWaterTwilight[] = INCGFX_U16("graphics/battle_environment/hns_pond_water/palette_morning.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_PondWaterNight[] = INCGFX_U16("graphics/battle_environment/hns_pond_water/palette_night.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_RockTwilight[] = INCGFX_U16("graphics/battle_environment/hns_rock/palette_morning.pal", ".gbapal");
const u16 gBattleEnvironmentPalette_RockNight[] = INCGFX_U16("graphics/battle_environment/hns_rock/palette_night.pal", ".gbapal");
