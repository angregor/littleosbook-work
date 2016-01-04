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

int print_a_letter(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
   	fb[i] = c;
	fb[i+1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
	return 0;
}

int write(char*buf,unsigned int len)
{
	unsigned int index = 0;
	unsigned short fb_index = 0;
	while(index < len)
	{
		print_a_letter(index*2, buf[index], 0, 2);
		fb_move_cursor(fb_index);
		index++;
		fb_index++;
	}
	return 0;
}

int print_hello_world()
{
	write("HELLO WORLD!", 12);

	return 0;
}
