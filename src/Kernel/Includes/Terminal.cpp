#include "Types.h"
#include "Terminal.h"

uint16_t Terminal::row = 0;
uint16_t Terminal::column = 0;
uint8_t Terminal::color = 0;
uint16_t* Terminal::buffer = 0;

Terminal::Terminal()
{
	row = 0;
	column = 0;
	color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	buffer = (uint16_t*) 0xB8000;
	for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
		for (uint16_t x = 0; x < VGA_WIDTH; x++) {
			const uint16_t index = y * VGA_WIDTH + x;
			buffer[index] = make_vgaentry(' ', color);
		}
	}
	write("Terminal Initialized\n");
}

Terminal::~Terminal()
{
	write("Terminal Deinitialized\n");
}

uint8_t Terminal::make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}
 
uint16_t Terminal::make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}
 


void Terminal::setcolor(uint8_t _color) {
	color = _color;
}
 
void Terminal::putentryat(char c, uint8_t color, uint16_t x, uint16_t y) {
	const uint16_t index = y * VGA_WIDTH + x;
	buffer[index] = make_vgaentry(c, color);
}


void Terminal::scroll()
{
	for (int x = 0; x < VGA_WIDTH; x++)
	{
		for (int y = 1; y < VGA_HEIGHT; y++)
		{
			buffer[(y-1) * VGA_WIDTH + x] = buffer[y * VGA_WIDTH + x];
		}
	}
	for (int x = 0; x < VGA_WIDTH; x++)
	{
		buffer[(VGA_HEIGHT-1) * VGA_WIDTH + x] = make_vgaentry(' ', color);
	}
	row--;
}
 
void Terminal::putchar(char c) {
	if (c=='\n')
	{
		column = 0;
		if (++row == VGA_HEIGHT) {
			scroll();
		}
	}
	else
	{
		putentryat(c, color, column, row);
		if (++column == VGA_WIDTH) {
			column = 0;
			if (++row == VGA_HEIGHT) {
				scroll();
			}
		}
	}
}
 
void Terminal::write(string data) {
	uint16_t datalen = strlen(data);
	for (uint16_t i = 0; i < datalen; i++)
		putchar(data[i]);
}

void Terminal::write(int i)
{
	bool neg = false;
	bool startsZero = false;
	//Replace with toString
	if (i < 0) { neg = true; i *= -1; }
	
	if ((i % 10) == 0) startsZero=true;
	
	int ii = 0;
	while (i != 0)
	{
		ii *= 10;
		ii += i % 10;
		i /= 10;
	}
	
	if (neg) putchar('-');

	while (ii != 0)
	{
		int b = ii % 10;
		putchar(((char)(b+48)));
		ii = ii / 10;
	}
	if (startsZero) putchar('0');
}
