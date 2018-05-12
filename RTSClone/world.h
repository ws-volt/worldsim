#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "unit.h"

class World {
public:
	World(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void Draw();
	void HandleEvent(const sf::Event& event);
	bool isGameComplete();

private:
	sf::RenderWindow& window;
	Unit testUnit;
	bool isGameOver;
};