#include "Tile.h";

Tile::Tile(int size, float xPos, float yPos, TileType type) : type(type) {
	setSize(sf::Vector2f(size, size));
	setPosition(xPos, yPos);

};