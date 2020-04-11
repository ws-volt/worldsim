#pragma once
#include "state.h"
#include "world.h"
#include "stateStack.h"
#include <SFML\Graphics.hpp>

class PlayState : public State {
public:
	PlayState(sf::RenderWindow& window, StateStack& stack);

	virtual void Update(sf::Time dt);
	virtual void Draw();
	virtual void HandleEvent(const sf::Event& event);
private:
	World gameWorld;
};