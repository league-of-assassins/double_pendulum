
//doublePendulum.hpp
#ifndef DOUBLEPENDULUM_HPP
#define DOUBLEPENDULUM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "common.hpp"

class DoublePendulum {
private:

	const double PI = 3.14159265358979323846;
	const double radToDeg = 180.0 / PI;
	const double degToRad = 1.0 / radToDeg;

	const double g = 9.81;

	static constexpr int PENDULUM_TOTAL = 2;

	const double L[PENDULUM_TOTAL] = { 1, 1 };  // Length of the pendulum arm
	const double m[PENDULUM_TOTAL] = { 20, 20 }; // Mass
	const double M = m[0] + m[1];

	double theta[PENDULUM_TOTAL] = { 130 * degToRad, 170 * degToRad }; // Initial angular displacement (radians)
	double velo[PENDULUM_TOTAL] = { 0, 0 }; // Initial angular velocity (radians / dt)


	const double dt = 1.0 / FPS; // Time step for simulation (deltaTime)



	struct CircleShape {

		sf::CircleShape shape;
		sf::Vector2f pos;
		double radius;

		CircleShape(double radius) : radius(radius) {

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

		RectangleShape(sf::Vector2f size, sf::Vector2f pos) : size(size), pos(pos) {

			shape.setSize(size);
			shape.setOrigin(size.x * 0.5, 0);
			shape.setPosition(pos);
			shape.setFillColor(sf::Color::Black);
			shape.setOutlineThickness(-1);
			shape.setOutlineColor(sf::Color::Red);
		}
	};


	CircleShape circle[PENDULUM_TOTAL] = {
		CircleShape(40),
		CircleShape(40)
	};

	RectangleShape box[PENDULUM_TOTAL] = {
		 RectangleShape(sf::Vector2f(10, 180), sf::Vector2f(400, 400)),
		 RectangleShape(sf::Vector2f(10, 180), sf::Vector2f(400, 400))
	};


	std::vector<sf::Vertex> line;



public:

	DoublePendulum();

	void update();

	void draw(sf::RenderWindow& window);


private:

	void formula();

	sf::Vector2f findEndPoint(const sf::Vector2f pos, const float size, const double radians);

	void setPos();
};


#endif // DOUBLEPENDULUM_HPP
