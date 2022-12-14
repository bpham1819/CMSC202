#include "Entity.h"

Entity::Entity() {}

Entity::Entity(string name, int health) {

  m_name = name;
  m_health = health;

}

Entity::~Entity() {}

string Entity::GetName() {
  return m_name;
}

int Entity::GetHealth() {
  return m_health;
}

void Entity::SetName(string name) {
  m_name = name;
}

void Entity::SetHealth(int health) {
  m_health = health;
}

ostream& operator<< (ostream& output, Entity& entity) {

  output << entity.m_name << "'s health: " << entity.m_health;
  return output;
  
}

