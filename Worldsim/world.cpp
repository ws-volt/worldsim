#include "world.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

World::World(sf::RenderWindow& window) : window(window), selector(), selectedEntities(), units(), worldMap() {
	//Unit u1 = Unit();
	//u1.setPosition(250, 250);
	//Unit u2 = Unit();
	//u1.setPosition(200, 200);
	//Unit u3 = Unit();
	//u1.setPosition(150, 150);
	//Unit u4 = Unit();
	//u1.setPosition(100, 100);
	//Unit u5 = Unit();
	//u1.setPosition(100, 250);
	//Unit u6 = Unit();
	//u1.setPosition(250, 100);


	sf::IntRect test = window.getViewport(window.getView());
	int a = 2;
	/*units.push_back(u1);
	units.push_back(u2);
	units.push_back(u3);
	units.push_back(u4);
	units.push_back(u5);
	units.push_back(u6);*/
}

void World::Update(sf::Time dt) {
	testUnit.update(dt);
}

void World::Draw() {
	for (Unit unit : units) {
		window.draw(unit);
	}
	window.draw(worldMap);
	window.draw(selector);
}

void World::HandleEvent(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) {
			break;
		}
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left) {
			break;
		}
	case sf::Event::MouseMoved:
		break;
	}
}

bool World::isGameComplete() {
	return isGameOver;
}

void World::handleSelectorCollisions() {
	if (selector.getSelectorBox().intersects(testUnit.getHitBox())) {
		selectedEntities.push_back(testUnit);
		testUnit.select();
	}
	else {
		for (int i = 0; i < selectedEntities.size(); i++) {
			Entity& entity = selectedEntities[i];
			entity.deselect();
			selectedEntities.erase(selectedEntities.begin() + i);
		}
	}
}
