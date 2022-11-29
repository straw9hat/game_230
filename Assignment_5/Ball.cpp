#include "Ball.h"
#include "Random.h"

using namespace sf;
using namespace gm;

Ball::Ball() {
	body.setPosition(400, Random::Range(1, 600));
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	move(Vector2f(PlayerMovementSpeedPerSecond * direction * deltaTime, 0));
}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Ball::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

void Ball::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	// Don't forget to update the Box's shape position to match the new position
	body.setPosition(position);
}

void Ball::setMovmentDirection(MovementDirection direction) {
	this->direction = direction;
}

MovementDirection Ball::getMovementDirection() const {
	return direction;
}


const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}