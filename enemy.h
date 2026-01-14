#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

typedef struct {
  char *name;
  int tier;
  Entity base;
  int drop_exp;
} Enemy;

int enemy_init_random(Enemy *out, int min_tier, int max_tier);
Enemy *enemy_create_random(int min_tier, int max_tier);
void enemy_destroy(Enemy *e);

#endif // !ENEMY_H
