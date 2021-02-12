/**
 * Example take from here:
 * https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;
  int rflag = 0;

  opterr = 0;

  // a and b are not followed by a colon
  // c is followed by a colon
  // The colon means that the preceding option takes an argument
  // so we could also put c:ab or c:ba instead of abc:
  while ((c = getopt (argc, argv, "abrc:")) != -1)
    switch (c)
      {
      case 'r':
        printf("You set the r flag!\n");
        rflag = 1;
        break;
      case 'a':
        printf("You set the a flag!\n");
        aflag = 1;
        break;
      case 'b':
        printf("You set the b flag!\n");
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        printf("You set the c flag with value %s\n", cvalue);
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}

