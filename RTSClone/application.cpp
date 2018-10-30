#include "application.h"
#include <SFML\Graphics.hpp>

const sf::Time Application::frameTime = sf::seconds(1.f / 144.f);

Application::Application() : window(sf::VideoMode(1500, 920), "blank", sf::Style::Close), stateStack(window) {

}

void Application::run() {
	sf::Clock clock;
	sf::Time timeElapsed = sf::Time::Zero;


	while (window.isOpen()) {
		timeElapsed += clock.restart();

		while (timeElapsed >= frameTime) {

			sf::Event event;
			while (window.pollEvent(event)) {	
				stateStack.handleEvent(event);

				switch (event.type) {
				case sf::Event::Closed:
					window.close();
				}
			}

			stateStack.update(frameTime);

			timeElapsed -= frameTime;
		}
		window.clear();
		stateStack.draw();
		window.display();
	}
}

