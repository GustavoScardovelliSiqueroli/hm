#include "player.h"
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>

const int PLAYER_MAX_EXP = 10;

Player *player_create() {
  Player *p = malloc(sizeof(Player));
  if (!p)
    return NULL;

  p->base = (Entity){100, 0, 0, 10};
  p->exp = 0;
  p->level = 1;
  return p;
}

void player_gain_exp(Player *p, int exp) {
  p->exp += exp;

  while (p->exp >= PLAYER_MAX_EXP) {
    p->exp -= PLAYER_MAX_EXP;
    p->level++;
  }
};

void player_destroy(Player *p) { free(p); }

void player_print(Player *p) {
  entity_print(&p->base);
  printf("\nmana: %.2f\n", p->mana);
  printf("level: %d\n", p->level);
  printf("exp: %d", p->exp);
}
