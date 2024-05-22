
#include "doublePendulum.hpp"


DoublePendulum::DoublePendulum() {

	box[0].shape.setRotation(theta[0] * radToDeg);
	box[1].shape.setRotation(theta[1] * radToDeg);

	setPos();
}


void DoublePendulum::draw(sf::RenderWindow& window) {

	if (line.size()) window.draw(&line[0], line.size(), sf::Lines);

	for (int i = 0; i < PENDULUM_TOTAL; i++) {
		window.draw(box[i].shape);
		window.draw(circle[i].shape);
	}
}




sf::Vector2f DoublePendulum::findEndPoint(const sf::Vector2f pos, const float size, const double radians) {

	return sf::Vector2f(pos.x + size * cos(radians), pos.y + size * sin(radians));
}


void DoublePendulum::setPos() {

	circle[0].pos = findEndPoint(box[0].pos, box[0].size.y, theta[0] + PI * 0.5);
	circle[0].shape.setPosition(circle[0].pos);

	box[1].pos = circle[0].pos;
	box[1].shape.setPosition(box[1].pos);

	circle[1].pos = findEndPoint(box[1].pos, box[1].size.y, theta[1] + PI * 0.5);
	circle[1].shape.setPosition(circle[1].pos);
}


void DoublePendulum::formula() {

	double theta0 = theta[0] - theta[1];

	double a = m[0] + m[1] * pow(sin(theta0), 2);

	if (a != 0) {
		velo[0] += (-sin(theta0) * (m[1] * L[0] * pow(velo[0], 2) * cos(theta0) + m[1] * L[1] * pow(velo[1], 2)) - g * (M * sin(theta[0]) - m[1] * sin(theta[1]) * cos(theta0))) / (L[0] * a) * dt;
		velo[1] += (+sin(theta0) * (M * L[0] * pow(velo[0], 2) + m[1] * L[1] * pow(velo[1], 2) * cos(theta0)) + g * (M * sin(theta[0]) * cos(theta0) - M * sin(theta[1]))) / (L[1] * a) * dt;
	}

	theta[0] += velo[0] * dt;
	theta[1] += velo[1] * dt;
}


void DoublePendulum::update() {

	//CALCULATE

	formula();


	//SET NEW VALUES

	box[0].shape.setRotation(theta[0] * radToDeg);
	box[1].shape.setRotation(theta[1] * radToDeg);

	setPos();


	//SET LINE POS

	do {
		line.push_back(sf::Vertex(circle[1].pos, sf::Color::White));
	} while (line.size() % 2 == 0);
}