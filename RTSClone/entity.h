#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {

public:
	Entity();
	virtual ~Entity();
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float x, float y);
	virtual void update(sf::Time dt);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private:
	sf::Vector2f velocity;

};