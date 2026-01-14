#include "dice.h"
#include "enemy.h"
#include "entity.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void print_waiting_int(char *pre_string, int (*funcao)()) {
  struct timespec t = {
      .tv_nsec = 800000000,
  };
  char wait_dots[4] = "...";

  for (int i = 2; i >= 0; i--) {
    printf("\r%s: %s", pre_string, wait_dots);
    fflush(stdout);
    nanosleep(&t, NULL);
    wait_dots[i] = ' ';
  }
  int result = funcao();
  printf("\r%s: %d", pre_string, result);
  fflush(stdout);
  nanosleep(&t, NULL);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  printf("******************************\n");

  char p_name[50];

  printf("nome: ");
  scanf("%s", p_name);
  Player *p1 = player_create();
  player_print(p1);

  // Player *p1 = player_create();
  //
  // entity_take_damage(&p1->base, 80);
  // printf("Vida do player apos tomar dano: %.1f\n", p1->base.health);
  //
  // Enemy e1;
  // enemy_init_random(&e1, 0, 1);
  //
  // printf("Inimigo selecioado: %s\n", e1.name);

  // Vai cair contra um inimigo aleatorio dentro de alguns predefinidos,
  // depois rodar o dado para descobrir quanto de dano vai dar / tomar

  printf("\n");
  return EXIT_SUCCESS;
}
