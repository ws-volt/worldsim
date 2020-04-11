#pragma once
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape {
public:
	Tile(int size, float xPos, float yPos);

private:
	int size;

};