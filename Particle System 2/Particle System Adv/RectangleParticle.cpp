#include "Game.h"
#include "Random.h"

using namespace gm;

extern int xPos, yPos;

RectangleParticle::RectangleParticle() {
	shape->setSize(sf::Vector2f(Random::Range(5, 40), Random::Range(5, 40)));
	shape->setPosition(xPos, yPos);
	shape->setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.5 - (float)Random::Range(1, 99) / 100, 0.5 - (float)Random::Range(1, 99) / 100);
}

void RectangleParticle::render(sf::RenderWindow& window) {
	window.draw(*shape);
}

RectangleParticle::~RectangleParticle() {

}