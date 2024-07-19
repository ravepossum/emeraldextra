#ifndef GUARD_POKEDEX_PLUS_HGSS_H
#define GUARD_POKEDEX_PLUS_HGSS_H

// the species to force to load if we open from the party menu
extern EWRAM_DATA u16 gSpeciesToLoad;

enum {
    HGSS_DEFAULT_PAL,
    HGSS_NATIONAL_PAL,
    HGSS_SEARCH_RESULTS_PAL,
    HGSS_SEARCH_MENU_PAL,
    HGSS_SILHOUETTE_PAL,
    HGSS_PAL_TYPE_COUNT
};

enum {
    HGSS_CLASSIC,
    HGSS_DARK,
    HGSS_DARKEST,
    HGSS_COLOR_COUNT
};

#define HGSS_COLOR_MODE HGSS_DARKEST
#define SCROLLING_MON_X 146
#define HGSS_DECAPPED TRUE
#define HGSS_HIDE_UNSEEN_EVOLUTION_NAMES FALSE

// For scrolling search parameter
#define MAX_SEARCH_PARAM_ON_SCREEN   6
#define MAX_SEARCH_PARAM_CURSOR_POS  (MAX_SEARCH_PARAM_ON_SCREEN - 1)

#define MAX_MONS_ON_SCREEN 4
#define MAX_EVOLUTION_ICONS 8

#define LIST_SCROLL_STEP         16

#define POKEBALL_ROTATION_TOP    64
#define POKEBALL_ROTATION_BOTTOM (POKEBALL_ROTATION_TOP - 16)

// Coordinates of the Pokémon sprite on its page (info/cry screens)
#define MON_PAGE_X 48
#define MON_PAGE_Y 56


void CB2_OpenPokedexPlusHGSS(void);
void Task_DisplayCaughtMonDexPageHGSS(u8);

#endif // GUARD_POKEDEX_PLUS_HGSS_H
