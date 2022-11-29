#include "CircleParticle.h"
#include "Random.h"

using namespace gm;
extern int xPos, yPos;

CircleParticle::CircleParticle() {
	lifeSpan = 1000;
	shape->setPosition(xPos, yPos);
	shape->setFillColor(sf::Color::White);
	velocity = sf::Vector2f(0.5 - (float)Random::Range(1, 99) / 100, 0.5 - (float)Random::Range(1, 99) / 100);
}

void CircleParticle::render(sf::RenderWindow &window) {
	window.draw(*shape);
}

CircleParticle::~CircleParticle() {

}