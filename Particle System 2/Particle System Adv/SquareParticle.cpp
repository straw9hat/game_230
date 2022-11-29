#include "SquareParticle.h"
#include "Random.h"

using namespace gm;

extern int xPos, yPos;

SquareParticle::SquareParticle() {
	int x = Random::Range(5, 40);
	shape->setSize(sf::Vector2f(x,x));
	shape->setPosition(xPos, yPos);
	shape->setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.5 - (float)Random::Range(1, 99) / 100, 0.5 - (float)Random::Range(1, 99) / 100);
}

void SquareParticle::render(sf::RenderWindow& window) {
	window.draw(*shape);
}

SquareParticle::~SquareParticle() {

}