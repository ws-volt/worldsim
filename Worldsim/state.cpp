#include "state.h"
#include <SFML\graphics.hpp>
#include "stateStack.h"

State::~State()
{
}

State::State(sf::RenderWindow& window, StateStack& stack) : window(window), mStack(&stack) {
}

sf::RenderWindow& State::getWindow() const {
	return window;
}

void State::popState() {
	mStack->popState();
}

