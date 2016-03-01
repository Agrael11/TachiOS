#ifndef TERMINAL
#define TERMINAL

#include "types.h"

class Terminal
{
public:
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

public:
	static uint16_t row;
	static uint16_t column;
	static uint8_t color;
	static uint16_t* buffer;

public:
	uint8_t make_color(enum vga_color fg, enum vga_color bg);
	uint16_t make_vgaentry(char c, uint8_t color);
	uint16_t strlen(string str);
	static const uint16_t VGA_WIDTH = 80;
	static const uint16_t VGA_HEIGHT = 25;
	void initialize();
	void setcolor(uint8_t color);
	void putentryat(char c, uint8_t color, uint16_t x, uint16_t y);
	void scroll();
	void putchar(char c);
	void write(string data);
	void write(int i);
};

#endif
