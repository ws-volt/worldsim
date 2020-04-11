#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "statestack.h"

class StateStack;

class State {
public:
	State(sf::RenderWindow& window, StateStack& stack);
	virtual ~State();

	virtual void Update(sf::Time dt) = 0;
	virtual void Draw() = 0;
	virtual void HandleEvent(const sf::Event& event) = 0;
	void popState();
	sf::RenderWindow& getWindow() const;


private:
	sf::RenderWindow& window;
	StateStack* mStack;
};