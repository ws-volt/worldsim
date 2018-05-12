#include "unit.h";
#include<SFML\Graphics.hpp>

Unit::Unit() {
	unitShape.setSize(sf::Vector2f(5, 5));
	unitShape.setPosition(50, 50);
}

void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(unitShape, states);
}

void Unit::update(sf::Time dt) {
	Entity::update(dt);
}
