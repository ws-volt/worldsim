#include "playState.h"
#include <SFML\Graphics.hpp>


PlayState::PlayState(sf::RenderWindow& window, StateStack& stack) : State(window, stack), gameWorld(window) {
}

void PlayState::Update(sf::Time dt) {
	if (!gameWorld.isGameComplete()) {
		gameWorld.Update(dt);
	}
	else {
		printf("Game over");
		popState();
	}
}

void PlayState::Draw() {
	gameWorld.Draw();
}

void PlayState::HandleEvent(const sf::Event& event) {
	gameWorld.HandleEvent(event);
}