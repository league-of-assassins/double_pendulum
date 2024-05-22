
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "common.hpp"
#include "doublePendulum.hpp"


int main() { 

	//--INITS--//
	sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "App", sf::Style::None));
	window.setFramerateLimit(FPS);


	std::unique_ptr<DoublePendulum> doublePendulum(new DoublePendulum);


	bool pause = false;

	//--WINDOW LOOP--//

	while (window.isOpen())
	{
		//EVENTS
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			else if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}

				else if (event.key.code == sf::Keyboard::P) {
					pause = !pause;
				}
			}
		}
		

		//UPDATES
		if (!pause) doublePendulum->update();


		//DISPLAY
		window.clear(sf::Color::Black);

		doublePendulum->draw(window);

		window.display();
	}
}