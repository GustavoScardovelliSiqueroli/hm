#include "entity.h"
#include <stdio.h>

void entity_take_damage(Entity *ent, float damage) {
  float liquid_damage = damage * (1.0f - ent->armor);
  float shield_result = ent->shield - liquid_damage;
  if (shield_result < 0) {
    ent->health += shield_result;
  } else {
    ent->shield = shield_result;
  }
  if (ent->health < 0) {
    ent->health = 0;
  }
}

void entity_print(Entity *ent) {
  printf("health: %.2f\n", ent->health);
  printf("shield: %.2f\n", ent->shield);
  printf("armor: %.2f\n", ent->armor);
  printf("power: %d", ent->power);
}
