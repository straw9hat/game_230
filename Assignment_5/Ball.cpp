#include "Ball.h"
#include "Random.h"

using namespace sf;
using namespace gm;

Ball::Ball(const Vector2f& position, const Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	velocity = Vector2f(200, 80);
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	move(deltaTime * velocity);
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



const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}