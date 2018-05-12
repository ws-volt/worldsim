#pragma once
#include "entity.h";
#include<SFML\Graphics.hpp>


class Unit : public Entity {
public: 
	Unit();

	void update(sf::Time dt);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape unitShape;
};