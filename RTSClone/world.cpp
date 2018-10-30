#include "world.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

World::World(sf::RenderWindow& window) : window(window), testUnit(), selector() {

}

void World::Update(sf::Time dt) {
	testUnit.update(dt);
}

void World::Draw() {
	window.draw(testUnit);
	window.draw(selector);
}

void World::HandleEvent(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			selector.activate();
			selector.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			selector.setStartPos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			break;
		}
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left) {
			selector.deactivate();
			break;
		}
	case sf::Event::MouseMoved:
		if (selector.isSelectorActive()) {
			selector.setSize(sf::Mouse::getPosition(window));
			break;
		}
	}
}

bool World::isGameComplete() {
	return isGameOver;
}
