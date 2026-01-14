#include "enemy.h"
#include <stdlib.h>

static const Enemy ENEMIES[] = {
    {
        .name = "goblin leve",
        .tier = 1,
        .base =
            {
                .health = 20,
                .shield = 0,
                .armor = 0,
                .power = 5,
            },
        .drop_exp = 5,
    },
    {
        .name = "goblin pesado",
        .tier = 1,
        .base =
            {
                .health = 33,
                .shield = 0,
                .armor = 0,
                .power = 3,
            },
        .drop_exp = 5,
    },

};

static const int ENEMIES_COUNT = sizeof(ENEMIES) / sizeof(ENEMIES[0]);

int enemy_get_max_tier() {
  if (ENEMIES_COUNT <= 0) {
    return -1;
  }
  int max_tier = 0;
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    if (ENEMIES[i].tier > max_tier) {
      max_tier = ENEMIES[i].tier;
    }
  }
  return max_tier;
}

int enemy_init_random(Enemy *out, int min_tier, int max_tier) {
  int valid_indexes[ENEMIES_COUNT];
  int count = 0;

  for (int i = 0; i < ENEMIES_COUNT; i++) {
    Enemy enm = ENEMIES[i];
    if (enm.tier >= min_tier && enm.tier <= max_tier) {
      valid_indexes[count++] = i;
    }
  }

  if (count == 0) {
    return -1;
  }

  int chosen = valid_indexes[rand() % count];

  *out = ENEMIES[chosen];
  return 0;
}
