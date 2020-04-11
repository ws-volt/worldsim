#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable {

public:
	Map();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Tile> mapTiles;

};