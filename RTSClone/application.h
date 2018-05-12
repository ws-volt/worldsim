#pragma once
#include <SFML/Graphics.hpp>
#include "statestack.h"

class Application {
public:
	Application();

	void run();

private:
	sf::RenderWindow window;
	static const sf::Time frameTime;
	StateStack stateStack;

};