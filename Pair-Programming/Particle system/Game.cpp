#include "Game.h"

using namespace gm;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {

}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput(sf::RenderWindow& window) {
	// Check for events from the window
	// E.g., is the window being closed?
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window, sf::CircleShape shape) {
	//std::cout << "Updating" << std::endl;
	shape.move(1, 1);
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window, sf::CircleShape obj) {
	// This clears the window at the beginning of every frame
	window.clear();

	window.draw(obj);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}