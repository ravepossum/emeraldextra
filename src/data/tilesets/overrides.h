static const u16 sTilesetPalOverride_General01_05[] = INCBIN_U16("data/tilesets/primary/general/override_palettes/01_05.gbapal");

static const u16 sTilesetPalOverride_General12[] = INCBIN_U16("data/tilesets/primary/general/override_palettes/12.gbapal");

static const u16 sTilesetPalOverride_Petalburg06_08_09[] = INCBIN_U16("data/tilesets/secondary/petalburg/override_palettes/06_08_09.gbapal");

static const u16 sTilesetPalOverride_Rustboro04[] = INCBIN_U16("data/tilesets/secondary/rustboro/override_palettes/04.gbapal");
static const u16 sTilesetPalOverride_Rustboro08_10_11[] = INCBIN_U16("data/tilesets/secondary/rustboro/override_palettes/08_10_11.gbapal");

static const u16 sTilesetPalOverride_Slateport04[] = INCBIN_U16("data/tilesets/secondary/slateport/override_palettes/04.gbapal");
static const u16 sTilesetPalOverride_Slateport06_08[] = INCBIN_U16("data/tilesets/secondary/slateport/override_palettes/06_08.gbapal");
static const u16 sTilesetPalOverride_Slateport10[] = INCBIN_U16("data/tilesets/secondary/slateport/override_palettes/10.gbapal");
//static const u16 sTilesetPalOverride_Slateport11[] = INCBIN_U16("data/tilesets/secondary/slateport/override_palettes/11.gbapal");
static const u16 sTilesetPalOverride_Slateport12[] = INCBIN_U16("data/tilesets/secondary/slateport/override_palettes/12.gbapal");

static const u16 sTilesetPalOverride_Mauville7[] = INCBIN_U16("data/tilesets/secondary/mauville/override_palettes/7.gbapal");
static const u16 sTilesetPalOverride_Mauville10[] = INCBIN_U16("data/tilesets/secondary/mauville/override_palettes/10.gbapal");

#define OVERRIDES_END { .slot = 0xFF, }

const struct PaletteOverride gTilesetPalOverrides_General[] =
{
    {
        .slot = 1,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_General01_05,
    },
    {
        .slot = 5,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_General01_05,
    },
    {
        .slot = 12,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_General12,
    },
    OVERRIDES_END
};

const struct PaletteOverride gTilesetPalOverrides_Petalburg[] =
{
    {
        .slot = 6,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Petalburg06_08_09,
    },
    {
        .slot = 8,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Petalburg06_08_09,
    },
    {
        .slot = 9,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Petalburg06_08_09,
    },
    OVERRIDES_END
};

const struct PaletteOverride gTilesetPalOverrides_Rustboro[] =
{
    {
        .slot = 4,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Rustboro04,
    },
    {
        .slot = 8,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Rustboro08_10_11,
    },
    {
        .slot = 10,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Rustboro08_10_11,
    },
    {
        .slot = 11,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Rustboro08_10_11,
    },
    OVERRIDES_END
};

const struct PaletteOverride gTilesetPalOverrides_Slateport[] =
{
    // {
    //     .slot = 4,
    //     .startHour = NIGHT_HOUR_BEGIN,
    //     .endHour = NIGHT_HOUR_END,
    //     .palette = sTilesetPalOverride_Slateport04,
    // },
    {
        .slot = 6,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Slateport06_08,
    },
    {
        .slot = 8,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Slateport06_08,
    },
    {
        .slot = 10,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Slateport10,
    },
    {
        .slot = 12,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Slateport12,
    },
    OVERRIDES_END
};

const struct PaletteOverride gTilesetPalOverrides_Mauville[] =
{
    {
        .slot = 7,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Mauville7,
    },
    {
        .slot = 10,
        .startHour = NIGHT_HOUR_BEGIN,
        .endHour = NIGHT_HOUR_END,
        .palette = sTilesetPalOverride_Mauville10,
    },
    OVERRIDES_END
};