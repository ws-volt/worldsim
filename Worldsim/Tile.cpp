#include "Tile.h";

Tile::Tile(int size, float xPos, float yPos) {
	setSize(sf::Vector2f(size, size));
	setPosition(xPos, yPos);
};