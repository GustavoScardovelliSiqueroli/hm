#include "dice.h"
#include "enemy.h"
#include "entity.h"
#include "menu.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

void clear() { system("clear"); }

char getch(void) {
  struct termios oldt, newt;
  char c;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  c = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return c;
}

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
  char p_name[50];
  char menu_response = '0';

  clear();

  printf("\nname: ");
  scanf("%s", p_name);

  Player *p1 = player_create();

  while (menu_response != 'q') {
    clear();
    printf("\n");
    menu_print();
    printf("\n");
    menu_response = getch();
    if (menu_response == '1') {
      clear();
      printf("\n");
      player_print(p1, p_name);
      getch();
    }
  }

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
