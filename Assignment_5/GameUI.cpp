#include "GameUI.h"

using namespace sf;
using namespace gm;

// Default constructor
GameUI::GameUI() {}



// Our position getter, NOTE the const reference return and marking the method itself const
const Vector2f& GameUI::getScore() const {
	//return position;
	return Vector2f(0,0);
}

// Our position setter, takes a Vector2f by const reference
void GameUI::setScore(const Vector2f& position) {
	//this->position = position;
	//collider.left = position.x;
	//collider.top = position.y;
}

GameUI::~GameUI() {}