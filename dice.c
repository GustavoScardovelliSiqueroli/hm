#include "dice.h"
#include <stdlib.h>

static int last_roll = 0;

int roll_dice() {
  last_roll = (rand() % 6) + 1;
  return last_roll;
}
int get_last_roll() { return last_roll; }
