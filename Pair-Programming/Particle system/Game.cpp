#include "Game.h"
#include <random>

using namespace gm;

#include "Random.h"

int xPos = 100, yPos = 100;
class Particle {
	public:
		sf::Vector2f velocity = sf::Vector2f((0.5 - (float)Random::Range(1,99) / 100)*10, (0.5 - (float)Random::Range(1, 99) / 100)*10);
		sf::Shape* shape;
		int lifespan = 50;
	
		Particle() {
			shape = new sf::CircleShape(Random::Range(5, 40));
			shape->setPosition(xPos, yPos);
			shape->setFillColor(sf::Color::White);
			bool isAlive = true;
		}
		~Particle() {
		}
		void update(sf::RenderWindow& window) {
			std::cout << "Updating" << std::endl;
		}
		void render(sf::RenderWindow& window) {
			window.draw(*shape);
		}
};

Particle p[10];

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
		if (event.key.code == sf::Mouse::Left) {
			xPos = sf::Mouse::getPosition(window).x;
			yPos = sf::Mouse::getPosition(window).y;
			for (int i = 0; i < 10; i++) {
				p[i].shape->setPosition(xPos, yPos);
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window) {
	
	for (int i = 0; i < 10; i++) {
		p[i].shape->move(p[i].velocity);
		std::cout << p[i].velocity.x << " " << p[i].velocity.y << std::endl;
		//p.shape->scale(1.2, 0.8);
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();
	for (int i = 0; i < 10; i++) {
		p[i].render(window);
	}

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}