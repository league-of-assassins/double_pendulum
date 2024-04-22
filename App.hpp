
//app.hpp
#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "doublePendulum.hpp"


class App {
private:

	sf::RenderWindow window;

	enum WindowSize {
		WINDOW_WIDTH = 800,
		WINDOW_HEIGHT = 800
	};

	const double fps = 144.0;

	sf::Event event;

	sf::Vector2i mousePos;
	bool mousePressed = false;

	bool paused = false;


	//OTHER CLASSES GO HERE

	DoublePendulum doublePendulum;



	void setWindow();

	void events();

	void displays();

public:

	App();
};


#endif //APP_HPP