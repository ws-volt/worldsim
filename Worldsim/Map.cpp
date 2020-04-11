#include "Map.h"

Map::Map() {
	Tile tile1 = Tile(10, 200, 200);
	mapTiles.push_back(tile1);
};

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Tile tile : mapTiles) {
		states.transform *= tile.getTransform();
		target.draw(tile, states);
	}
}

