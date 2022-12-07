#include "AIController.h"

using namespace sf;
using namespace gm;

// Default constructor
AIController::AIController() {}



// Our position getter, NOTE the const reference return and marking the method itself const
void AIController::update(sf::RenderWindow& window) {

}

// Our position setter, takes a Vector2f by const reference
int AIController::sense(const sf::Vector2f& paddlePosition, const sf::Vector2f& ballPosition) {
	if (ballPosition.y > paddlePosition.y)
	{
		return 1;
	}
	else if (ballPosition.y < paddlePosition.y)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

AIController::~AIController() {}