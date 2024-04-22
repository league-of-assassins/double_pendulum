
//doublePendulum.hpp
#ifndef DOUBLEPENDULUM_HPP
#define DOUBLEPENDULUM_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>



class DoublePendulum {
public:

	enum {
		PENDULUM_TOTAL = 2
	};


	struct CircleShape {

		sf::CircleShape shape;
		sf::Vector2f pos;
		float radius = 40;

		CircleShape() {

			shape.setRadius(radius);
			
			shape.setOrigin(radius, radius);

			shape.setFillColor(sf::Color::Black);
			shape.setOutlineThickness(-1);
			shape.setOutlineColor(sf::Color::Blue);
		}
	};

	struct RectangleShape {

		sf::RectangleShape shape;
		sf::Vector2f pos;
		sf::Vector2f size;

		RectangleShape() {
			
			size.x = 10;
			size.y = 180;
			shape.setSize(size);

			shape.setOrigin(size.x * 0.5, 0);

			pos.x = 400;
			pos.y = 200;
			shape.setPosition(pos);

			shape.setFillColor(sf::Color::Black);
			shape.setOutlineThickness(-1);
			shape.setOutlineColor(sf::Color::Red);
		}
	};

	CircleShape circle[PENDULUM_TOTAL];
	RectangleShape box[PENDULUM_TOTAL];


	const double M_PI = 3.14159265359;
	const double radToDeg = 180 / M_PI;
	const double g = 9.81;

	const double L[PENDULUM_TOTAL] = { 1, 1 };  // Length of the pendulum arm
	const double m[PENDULUM_TOTAL] = { 50, 20 }; // Mass
	const double M = m[0] + m[1];

	double theta[PENDULUM_TOTAL] = { 170 * (1 / radToDeg), 170 * (1 / radToDeg) }; // Initial angular displacement (radians)
	double velo[PENDULUM_TOTAL] = { 0, 0 }; // Initial angular velocity (radians)

	const double fps = 144.0;
	const double speed = 1.0; //Animation speed
	const double dt = speed / fps; // Time step for simulation (deltaTime)


	//line
	struct Line {
		std::vector<sf::Vertex> shape;
		int count = 0;
	};

	Line line[2];


	DoublePendulum();

	void logic();

	void formula();

	void setCirclePos(const int& i);

	void setPos();

	void draw(sf::RenderWindow& window);
};


#endif // DOUBLEPENDULUM_HPP

