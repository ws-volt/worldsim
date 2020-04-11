#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "unit.h"
#include "Map.h"
#include "selector.h"

class World {
public:
	World(sf::RenderWindow& window);
	void Update(sf::Time dt);
	void Draw();
	void HandleEvent(const sf::Event& event);
	bool isGameComplete();
	void handleSelectorCollisions();

private:
	sf::RenderWindow& window;
	Unit testUnit;
	Selector selector;
	Map worldMap;
	bool isGameOver;
	bool isSelecting;
	std::vector<std::reference_wrapper<Entity>> selectedEntities;
	std::vector<std::reference_wrapper<Unit>> units;
};