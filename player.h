#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

typedef struct {
  Entity base;
  float mana;
  int level;
  int exp;
} Player;

void player_gain_exp(Player *p, int exp);

Player *player_create();

#endif // !PLAYER_H
