#include "entity.h"

void entity_take_damage(Entity *p, float damage) {
  float liquid_damage = damage * (1.0f - p->armor);
  float shield_result = p->shield - liquid_damage;
  if (shield_result < 0) {
    p->health += shield_result;
  } else {
    p->shield = shield_result;
  }
  if (p->health < 0) {
    p->health = 0;
  }
}
