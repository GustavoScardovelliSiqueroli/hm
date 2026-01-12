#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

typedef struct {
  char *name;
  int tier;
  Entity base;
  int drop_exp;
} Enemy;

int get_enemy(Enemy *out, int min_tier, int max_tier);

#endif // !ENEMY_H
