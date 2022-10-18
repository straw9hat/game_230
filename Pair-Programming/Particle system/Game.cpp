#include "Game.h"
#include <random>

using namespace gm;


std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> range(1, 100);

int xPos = 0, yPos = 0;
sf::Shape* shape;
class Particle {
	public:
		sf::Vector2f velocity = sf::Vector2f(0.5 - range(rng)/100, 0.5 - range(rng)/100);
		int lifespan = 50;
	
		Particle() {
			shape = new sf::CircleShape(23);
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
			
		}
};

Particle p;

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
			p.~Particle();
			Particle p;
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window) {
	std::cout << p.velocity.x << " " << p.velocity.y << std::endl;
	shape->move(p.velocity);
		//p.shape->scale(1.2, 0.8);
	
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();
	window.draw(*shape);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}