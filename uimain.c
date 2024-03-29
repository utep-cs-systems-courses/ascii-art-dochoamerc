#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Arrow = a, Chars = c, 5x7 Chars = n, 8x12 Chars = m, 12x8 Chars = b) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'a':
      puts("You selected arrow:");
      print_arrow(5,7);
      break;
    case 'c':
      puts("You selected chars:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_11x16(c);
      break;
    case 'n':
      puts("You selected 5x7 chars:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_5x7(c);
      break;
    case 'm':
      puts("You selected 8x12 chars:");
      for(char c = 'A'; c < 'D'; c++)
	print_char_8x12(c);
      break;
    case 'b':
      puts("You selected 12x8 Upside-Down chars:");
      for(char c = 'A'; c < 'D'; c++)
	print_char_12x8(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
