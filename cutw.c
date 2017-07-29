#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  
  // Parse options.
  int index = 0;
  char opt;
  while ((opt = getopt (argc, argv, "f:")) != -1) {
    switch (opt)
      {
      case 'f':
	index = atoi(optarg);
	break;
      case 'h':
      default:
	printf("help file to come soon.\n");
	return 0;
      }
  }
  
  int cur_index = index;
  char c = ' ';

  int currently_whitespace = 0;
  while (c != EOF) {
      c = getchar();
      switch (c) 
	{
	case ' ':
	case '\t':
	case '\v':
	case '\f':
	case '\r':
	  // Mark that we're in whitespace.
	  currently_whitespace = 1;
	case EOF:
	  break;
	case '\n':
	  // Reset on a new line
	  printf("\n");
	  cur_index = index;
	  currently_whitespace = 0;
	  break;
	default:
	  // If we were in whitespace and now are in a character,
	  // we've moved to the next 'column', so decrement the index.
	  if (currently_whitespace == 1) {
	    cur_index = cur_index - 1;
	    currently_whitespace = 0;
	  }
	  if (cur_index == 1)
	    printf("%c", c);
	}
  }
  
  
  return 0;
}
