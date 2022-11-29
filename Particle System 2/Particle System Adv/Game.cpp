#include "Game.h"
#include "CircleParticle.h"
#include "CircleParticleEffect.h"
#include "Particle.h"
#include "ParticleEffect.h"
#include "RectangleParticle.h"
#include "RectangleParticleEffect.h"
#include "SquareParticle.h"
#include "SquareParticleEffect.h"

using namespace gm;



ParticleEffect* p;
short choice = 1;
int ctr;
int xPos = -5000, yPos = -5000;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() {
	p = new CircleParticleEffect();
	ctr = p->particleArray[0].lifeSpan;
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
		if (event.key.code == sf::Keyboard::Q) {
			choice = 1;
		}
		if (event.key.code == sf::Keyboard::W) {
			choice = 2;
		}
		if (event.key.code == sf::Keyboard::E) {
			choice = 3;
		}
		if (event.key.code == sf::Mouse::Left) {
			ctr = p->particleArray[0].lifeSpan;
			if (choice == 1) {
				delete p;
				p = new CircleParticleEffect();
			}
			else if (choice == 2) {
				delete p;
				p = new SquareParticleEffect();
			}
			else if (choice == 3) {
				delete p;
				p = new RectangleParticleEffect();
			}
			xPos = sf::Mouse::getPosition(window).x;
			yPos = sf::Mouse::getPosition(window).y;
			std::cout << xPos << " " << yPos << std::endl;
			for (int i = 0; i < 10; i++) {
					p->particleArray[i].shape->setPosition(xPos, yPos);
					p->particleArray[i].velocity = sf::Vector2f(0.5 - (float)Random::Range(1, 99) / 100, 0.5 - (float)Random::Range(1, 99) / 100);	
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update(sf::RenderWindow& window) {
	//std::cout << "Updating" << std::endl;
	ctr--;
	if (ctr == 0) {
		ctr = p->particleArray[0].lifeSpan;
		if (choice == 1) {
			delete p;
			p = new CircleParticleEffect();
		}
		else if (choice == 2) {
			delete p;
			p = new SquareParticleEffect();
		}
		else if (choice == 3) {
			delete p;
			p = new RectangleParticleEffect();
		}
		for (int i = 0; i < 10; i++) {
			p->particleArray[i].shape->setPosition(xPos, yPos);
			p->particleArray[i].velocity = sf::Vector2f(0.5 - (float)Random::Range(1, 99) / 100, 0.5 - (float)Random::Range(1, 99) / 100);
		}
	}
	p->update(window);
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render(sf::RenderWindow& window) {
	// This clears the window at the beginning of every frame
	window.clear();

	p->render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}