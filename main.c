#include "dice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  time_t time_now = time(NULL);
  printf("time now: %s\n", ctime(&time_now));

  printf("%d\n", roll_dice());
  printf("%d\n", roll_dice());
  printf("%d\n", roll_dice());

  printf("\nLast number rolled: %d\n\n", get_last_roll());
  return EXIT_SUCCESS;
}
