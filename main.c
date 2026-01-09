#include "dice.h"
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clear() { system("clear"); }

void print_rolling_dice(int (*funcao)()) {
  struct timespec t = {
      .tv_sec = 0,
      .tv_nsec = 200000000,
  };
  for (int i = 2; i >= 0; i--) {
    static char test[4] = "...";
    printf("\n🎲: %s\n", test);
    nanosleep(&t, NULL);
    test[i] = '\0';
    clear();
  }
  int result = funcao();
  printf("\n🎲: %d\n", result);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  clear();

  print_rolling_dice(roll_dice);

  Entity entity_test = {
      .health = 100,
      .armor = .1,
      .power = 10,
      .shield = 5,
  };

  entity_take_damage(&entity_test, 100);
  printf("Vida apos tomar dano: %.1f\n", entity_test.health);

  return EXIT_SUCCESS;
}
