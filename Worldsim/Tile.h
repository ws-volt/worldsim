#pragma once
#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable, public sf::Transformable, public sf::RectangleShape {
public:
	Tile();

private:
	int size;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};