#include "world.h"
#include <SFML\Graphics.hpp>

World::World(sf::RenderWindow& window) : window(window), testUnit() {

}

void World::Update(sf::Time dt) {

}

void World::Draw() {
	window.draw(testUnit);
}

void World::HandleEvent(const sf::Event& event) {

}

bool World::isGameComplete() {
	return isGameOver;
}
