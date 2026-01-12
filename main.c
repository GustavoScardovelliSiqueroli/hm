#include "dice.h"
#include "enemy.h"
#include "entity.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clear() { system("clear"); }

void print_waiting_int(char *pre_string, int (*funcao)()) {
  struct timespec t = {
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

void start_game(Player *p) {
  Entity pb = {100, 0, 0, 10};
  p->base = pb;
  p->exp = 0;
  p->level = 1;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  clear();

  Player p1;
  start_game(&p1);

  entity_take_damage(&p1.base, 80);
  printf("Vida do player apos tomar dano: %.1f\n", p1.base.health);

  Enemy e1;
  get_enemy(&e1, 0, 1);

  printf("Inimigo selecioado: %s\n", e1.name);

  // Vai cair contra um inimigo aleatorio dentro de alguns predefinidos,
  // depois rodar o dado para descobrir quanto de dano vai dar / tomar

  return EXIT_SUCCESS;
}
