#include "selector.h";
#include<SFML\Graphics.hpp>

Selector::Selector() {
	selectorShape.setFillColor(sf::Color(0, 0, 0, 0));
	selectorShape.setOutlineColor(sf::Color(101, 153, 237, 200));
	selectorShape.setOutlineThickness(1);
}

void Selector::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(selectorShape, states);
}

void Selector::update(sf::Time dt) {
	Entity::update(dt);
}

void Selector::setSize(sf::Vector2i mousePos) {
	float sizeX =  mousePos.x - startX;
	float sizeY = mousePos.y - startY;
	selectorShape.setSize(sf::Vector2f(sizeX, sizeY));
}

void Selector::activate() {
	isActive = true;
}

void Selector::deactivate() {
	isActive = false;
	selectorShape.setSize(sf::Vector2f(0, 0));
}

bool Selector::isSelectorActive() {
	return isActive;
}

void Selector::setStartPos(float x, float y) {
	startX = x;
	startY = y;
}
