#include "dice.h"
#include "entity.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clear() { system("clear"); }

void print_waiting_int(char *pre_string, int (*funcao)()) {
  struct timespec t = {
      .tv_sec = 0,
      .tv_nsec = 200000000,
  };
  char wait_dots[4] = "...";

  for (int i = 2; i >= 0; i--) {
    clear();
    printf("\n%s: %s\n", pre_string, wait_dots);
    nanosleep(&t, NULL);
    wait_dots[i] = '\0';
  }
  clear();
  int result = funcao();
  printf("\n%s: %d\n", pre_string, result);
  nanosleep(&t, NULL);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  clear();

  print_waiting_int("🎲", roll_dice);

  printf("\n");

  Entity entity_test = {
      .health = 100,
      .armor = .1,
      .power = 10,
      .shield = 5,
  };

  Player p1 = {
      .base =
          {
              .health = 100,
              .armor = .1,
              .power = 10,
              .shield = 5,
          },
      .mana = 100,
  };

  entity_take_damage(&p1.base, 100);
  printf("Vida do player apos tomar dano: %.1f\n", p1.base.health);

  return EXIT_SUCCESS;
}
