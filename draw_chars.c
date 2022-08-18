#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_5x7(char c)
{
  c -= 0x20; //this is to skip over first 20 ascii chars
  for(char row = 0; row < 5; row++) {
    unsigned char rowBits = font_5x7[c][row];
    for (char col = 0; col < 7; col++) {
      unsigned char colMask = 1 << (6-col); // 1 shifts per space necessary for the col we are on
      putchar( (rowBits & colMask) ? '*' : ' '); // prints out a star where rowBits and mask are 1
    }
    putchar('\n');
  }
}

void print_char_8x12(char c) // making standing letters
{
  c -= 0x20; //skipping first 20 unprintables
  for(char col = 0; col < 8; col++) {
    unsigned char colMask = 1 << (7-col);
    for (char row = 12; row > 0; row--) {
      unsigned char rowBits = font_8x12[c][row];
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}


void print_char_12x8(char c) // making standing letters
{
  char row, col;
  c -= 0x20; //skipping first 20 unprintables
  for(col = 12; col > 0; col--) {
    unsigned char rowBits = font_8x12[c][col];
    for (row = 8; row >0; row--) {
      unsigned char colMask = 1 << (7-row);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
