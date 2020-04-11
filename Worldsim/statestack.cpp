#include "statestack.h"
#include "state.h"
#include "playState.h"
#include <SFML\Graphics.hpp>

StateStack::StateStack(sf::RenderWindow& window) : window(window) {
	PlayState *defaultPlayState = new PlayState(window, *this);
	pushState(*defaultPlayState);
}

void StateStack::popState() {
	states.pop_back();
}

void StateStack::pushState(State& state) {
	states.push_back(state);
}

State& StateStack::getCurrentState() {
	return states.back();
}

void StateStack::update(sf::Time dt) {
	State& state = states.back();
	state.Update(dt);
}

void StateStack::handleEvent(const sf::Event& event) {
	State& state = states.back();
	state.HandleEvent(event);
}

void StateStack::draw() {
	State& state = states.back();
	state.Draw();
}