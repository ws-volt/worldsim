#include "Map.h"
#include "Deluanator.hpp"

Map::Map() {
	Tile tile1 = Tile(1, 1800, 300, TileType::Land);
	//mapTiles.push_back(tile1);
	generateWorld();
};

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Tile tile : mapTiles) {
		target.draw(tile, states);
	}
}

void Map::generateWorld() {
	/*Tile start = Tile(2, 700, 700, TileType::Land);*/
	generateLandmass(10);


}

std::vector<Tile> Map::generateLandmass(int numSides) {
	int fudge = std::ceil(numSides / 10);
	std::vector<sf::Vector2f> points;
	std::vector<double> coords;
	std::srand(time(NULL));

	// generate random points equal to the number of sides + fudge factor
	for (int i = 0; i < numSides + fudge; i++) {
		float pointX = std::rand() % (0 - 500 + 1);
		float pointY = std::rand() % (0 - 500 + 1);
		sf::Vector2f point = sf::Vector2f(pointX, pointY);

		coords.push_back(pointX);
		coords.push_back(pointY);

		points.push_back(point);
	}

	delaunator::Delaunator d(coords);

	// build tiles from all triangles 
	for (std::size_t i = 0; i < d.triangles.size(); i += 3) {
		double x1 = d.coords[2 * d.triangles[i]];        //tx0
		double y1 = d.coords[2 * d.triangles[i] + 1];    //ty0

		Tile tempTile = Tile(1, x1, y1, TileType::Land);
		mapTiles.push_back(tempTile);


		double x2 = d.coords[2 * d.triangles[i + 1]];    //tx1
		double y2 = d.coords[2 * d.triangles[i + 1] + 1]; //ty1

		Tile tempTile2 = Tile(1, x2, y2, TileType::Land);
		mapTiles.push_back(tempTile2);

		double x3 = d.coords[2 * d.triangles[i + 2]];    //tx2
		double y3 = d.coords[2 * d.triangles[i + 2] + 1]; //ty2

		Tile tempTile3 = Tile(1, x3, y3, TileType::Land);
		mapTiles.push_back(tempTile3);

		// plot lines between points of a triangle
		std::vector<Tile> t0t1 = lineBetweenTwoPoints(x1, y1, x2, y2);
		std::vector<Tile> t0t2 = lineBetweenTwoPoints(x1, y1, x3, y3);
		std::vector<Tile> t2t3 = lineBetweenTwoPoints(x2, y2, x3, y3);
		mapTiles.insert(mapTiles.end(), t0t1.begin(), t0t1.end());
		mapTiles.insert(mapTiles.end(), t0t2.begin(), t0t2.end());
		mapTiles.insert(mapTiles.end(), t2t3.begin(), t2t3.end());
	}
	return mapTiles;
}


std::vector<Tile> Map::lineBetweenTwoPoints(double x1, double y1, double x2, double y2) {
	int xdiff = x2 - x1;
	int ydiff = y2 - y1;
	int step = 1;

	double xDirection = 0;
	double yDirection = 0;

	double slope = (y2 - y1) / (x2 - x1);

	if(xdiff > 0) {
		xDirection = step * slope;
	}
	else if(xdiff < 0) {
		xDirection = step * slope;
	}

	if (ydiff > 0) {
		yDirection = step * slope;
	}
	else if (ydiff < 0) {
		yDirection = step * slope;
	}

	int currX = x1;
	int currY = y1;

	double quant = 500;

	std::vector<Tile> line;

	for(int i=0;i<quant;i++) {
		//currX += xDirection;
		//currY += yDirection;
		float dy = 0;
		float dx = 0;
		if (slope != 0) {
			dy = ydiff * (i / quant);
			dx = dy / slope;
		}
		else {
			dx = xdiff * (i / quant);
		}

		Tile tempTile = Tile(1, x1+dx, y1+dy, TileType::Land);
		line.push_back(tempTile);
	}

	return line;
}



