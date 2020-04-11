#include "Entity.h"
#include <SFML\Graphics.hpp>

Entity::~Entity() {

}

Entity::Entity() : velocity(0.f, 0.f) {

}

sf::Vector2f Entity::getVelocity() {
	return velocity;
}

void Entity::setVelocity(sf::Vector2f vel) {
	velocity = vel;
}

void Entity::setVelocity(float x, float y) {
	velocity.x = x;
	velocity.y = y;
}

void Entity::update(sf::Time dt) {
	move(velocity * dt.asSeconds());
}

bool Entity::isSelected() {
	return selected;
}

void Entity::select() {
	selected = true;
}

void Entity::deselect() {
	selected = false;
}
