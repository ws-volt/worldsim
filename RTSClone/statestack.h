#pragma once
#include "state.h"
#include <SFML\Graphics.hpp>

class State;

class StateStack : public sf::NonCopyable {
public:
	explicit StateStack(sf::RenderWindow& window);
	void popState();
	void pushState(State& state);
	State& getCurrentState();
	void update(sf::Time dt);
	void draw();
	void handleEvent(const sf::Event& event);

private:
	sf::RenderWindow& window;
	std::vector<std::reference_wrapper<State>> states;
};