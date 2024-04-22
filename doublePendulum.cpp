
#include "doublePendulum.hpp"

DoublePendulum::DoublePendulum() {

	box[0].shape.setRotation(theta[0] * radToDeg);
	box[1].shape.setRotation(theta[1] * radToDeg);

	setPos();
}

void DoublePendulum::draw(sf::RenderWindow& window) {

	if (line[0].count != 0) window.draw(&line[0].shape[0], line[0].count, sf::Lines);
	if (line[1].count != 0) window.draw(&line[1].shape[0], line[1].count, sf::Lines);

	for (int i = 0; i < 2; i++) {
		window.draw(box[i].shape);
		window.draw(circle[i].shape);
	}
}


void DoublePendulum::setCirclePos(const int& i) {

	const float radians = theta[i] + M_PI * 0.5;

	circle[i].pos.x = box[i].pos.x + box[i].size.y * cos(radians);
	circle[i].pos.y = box[i].pos.y + box[i].size.y * sin(radians);

	circle[i].shape.setPosition(circle[i].pos);
}

void DoublePendulum::setPos() {

	setCirclePos(0);

	box[1].pos = circle[0].pos;
	box[1].shape.setPosition(box[1].pos);

	setCirclePos(1);
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

void DoublePendulum::logic() {

	formula();


	//SET NEW VALUES

	box[0].shape.setRotation(theta[0] * radToDeg);
	box[1].shape.setRotation(theta[1] * radToDeg);

	setPos();


	//SET LINE POS

	line[0].shape.push_back(sf::Vertex(circle[1].pos, sf::Color::White));
	line[0].count++;

	if (line[0].count != 1) {
		line[1].shape.push_back(sf::Vertex(circle[1].pos, sf::Color::White));
		line[1].count++;
	}
}