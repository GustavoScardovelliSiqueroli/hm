#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
  float health;
  float shield;
  float armor;
  int power;
} Entity;

void entity_take_damage(Entity *ent, float damage);
void entity_print(Entity *ent);

#endif
