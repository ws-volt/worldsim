#pragma once
#include <SFML/Graphics.hpp>

enum class TileType{ Sea, Land };

class Tile : public sf::RectangleShape {
public:
	Tile(int size, float xPos, float yPos, TileType type);


private:
	int size;

	TileType type;
};