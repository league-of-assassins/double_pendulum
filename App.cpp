
#include "App.hpp"


void App::setWindow() {
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "App", sf::Style::None);
	window.setFramerateLimit(fps);
}


void App::events() {
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();

		else if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}

			else if (event.key.code == sf::Keyboard::P) {
				paused = !paused;
			}
		}
	}
}


void App::displays() {

	window.clear(sf::Color::Black);

	doublePendulum.draw(window);

	window.display();
}



App::App() {

	//--INITS--//

	setWindow();

	
	//--WINDOW LOOP--//

	while (window.isOpen())
	{
		events();

		if (!paused) doublePendulum.logic();

		displays();
	}
}