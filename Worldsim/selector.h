#pragma once
#pragma once
#include "entity.h";
#include<SFML\Graphics.hpp>


class Selector : public Entity {
public:
	Selector();

	void update(sf::Time dt);
	void setSize(sf::Vector2i mousePos);
	void activate();
	void deactivate();
	bool isSelectorActive();
	void setStartPos(float x, float y);
	sf::FloatRect getSelectorBox() const;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
	bool isActive;
	float startX;
	float startY;
	sf::RectangleShape selectorShape;
};