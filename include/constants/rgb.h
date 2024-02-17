#ifndef GUARD_RGB_H
#define GUARD_RGB_H

#define GET_R(color) ((color) & 0x1F)
#define GET_G(color) (((color) >> 5) & 0x1F)
#define GET_B(color) (((color) >> 10) & 0x1F)

#define RGB(r, g, b)  ((r) | ((g) << 5) | ((b) << 10))
#define RGB2(r, g, b) (((b) << 10) | ((g) << 5) | (r))
#define _RGB(r, g, b) ((((b) & 0x1F) << 10) + (((g) & 0x1F) << 5) + ((r) & 0x1F))
#define RGB2GBA(r, g, b) (((r >> 3) & 31) | (((g >> 3) & 31) << 5) | (((b >> 3) & 31) << 10))

#define RGB_ALPHA       (1 << 15)
#define IS_ALPHA(color) ((color) & RGB_ALPHA)

#define RGB_BLACK      RGB(0, 0, 0)
#define RGB_WHITE      RGB(31, 31, 31)
#define RGB_RED        RGB(31, 0, 0)
#define RGB_GREEN      RGB(0, 31, 0)
#define RGB_BLUE       RGB(0, 0, 31)
#define RGB_PURPLE     RGB(24, 0, 24)
#define RGB_YELLOW     RGB(31, 31, 0)
#define RGB_MAGENTA    RGB(31, 0, 31)
#define RGB_CYAN       RGB(0, 31, 31)
#define RGB_WHITEALPHA (RGB_WHITE | RGB_ALPHA)

#define RGB_LIME_GREEN  RGB2GBA(222, 230, 49)

// dark mode UI colors
#define RGB_UI_DARK_BLACK        RGB(3, 3, 3)
#define RGB_UI_DARK_TEXT_SHADOW  RGB(9, 9, 9)
#define RGB_UI_DARK_FRAME_BORDER RGB(8, 8, 8)
#define RGB_UI_DARK_FRAME_CORNER RGB(11, 12, 11)
#define RGB_UI_SHOP_OUTER_BORDER RGB(4, 11, 14)
#define RGB_UI_SHOP_INNER_BORDER RGB(5, 6, 9)
#define RGB_UI_SHOP_LIGHT        RGB(7, 10, 12)
#define RGB_UI_SHOP_DARK         RGB(2, 3, 5)

#endif // GUARD_RGB_H
