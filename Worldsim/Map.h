#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable {

public:
	Map();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Tile> mapTiles;
	void generateWorld();


	std::vector<Tile> generateLandmass(int numSides);

	std::vector<Tile> lineBetweenTwoPoints(double x1, double y1, double x2, double y2);
};