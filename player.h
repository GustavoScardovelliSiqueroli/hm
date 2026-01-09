#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

typedef struct {
  Entity base;
  float mana;
  int level;
  int exp;
} Player;

void gain_exp(Player *p, int exp);

#endif // !PLAYER_H
