#include "io.h"

#define FB_COMMAND_PORT	0x3D4
#define FB_DATA_PORT	0x3D5

#define FB_HIGH	14
#define FB_LOW	15

char* fb = (char *)0x000B8000;

void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_driver()
{
	fb_move_cursor(50000);
}

int print_a_letter(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
   	fb[i] = c;
	fb[i+1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
	return 0;
}

int print_hello_world()
{
	print_a_letter(0,'H',2,8);
	print_a_letter(2,'E',2,8);
	print_a_letter(4,'L',2,8);
	print_a_letter(6,'L',2,8);
	print_a_letter(8,'0',2,8);
	print_a_letter(10,' ',2,8);
	print_a_letter(12,'W',2,8);
	print_a_letter(14,'O',2,8);
	print_a_letter(16,'R',2,8);
	print_a_letter(18,'L',2,8);
	print_a_letter(20,'D',2,8);

	return 0;
}
