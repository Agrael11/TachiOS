#ifndef TERMINAL
#define TERMINAL

#include "types.h"

enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

extern uint16_t terminal_row;
extern uint16_t terminal_column;
extern uint8_t terminal_color;
extern uint16_t* terminal_buffer;

uint8_t make_color(enum vga_color fg, enum vga_color bg);

uint16_t make_vgaentry(char c, uint8_t color);

uint16_t strlen(string str);

static const uint16_t VGA_WIDTH = 80;
static const uint16_t VGA_HEIGHT = 25;

extern void terminal_initialize();

void terminal_setcolor(uint8_t color);

void terminal_putentryat(char c, uint8_t color, uint16_t x, uint16_t y);


void terminal_scroll();

void terminal_putchar(char c);

void terminal_write(string data);

void terminal_write(int i);


#endif
