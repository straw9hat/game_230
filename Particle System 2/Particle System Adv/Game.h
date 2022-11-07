// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* STL Includes */
#include <iostream>
#include "Random.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Game Loop Programming Pattern Methods
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		// Destructor
		~Game();
	};

	class Particle {
		public:
			
			int lifeSpan;
			bool isAlive;
			Particle();
			void update(sf::RenderWindow& window);
			virtual void render(sf::RenderWindow& window) = 0;
			~Particle();
	};

	class CircleParticle : Particle {
		private:
			
		public:
			int lifeSpan = 1000;
			sf::Vector2f position;
			sf::Vector2f velocity;
			sf::CircleShape* shape = new sf::CircleShape(Random::Range(5, 40));
			CircleParticle();
			void render(sf::RenderWindow& window);
			~CircleParticle();
	};

	class SquareParticle : Particle {
	private:

	public:
		int lifeSpan = 1000;
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::RectangleShape* shape = new sf::RectangleShape();
		SquareParticle();
		void render(sf::RenderWindow& window);
		~SquareParticle();
	};

	class RectangleParticle : Particle {
	private:

	public:
		int lifeSpan = 1000;
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::RectangleShape* shape = new sf::RectangleShape();
		RectangleParticle();
		void render(sf::RenderWindow& window);
		~RectangleParticle();
	};

	class ParticleEffect {
	public:
		int size = 10;
		CircleParticle* particleArray = new CircleParticle[size];
	public:
		ParticleEffect();
		virtual void update(sf::RenderWindow& window) = 0;
		virtual void render(sf::RenderWindow& window) = 0;
		~ParticleEffect();
	};

	class CircleParticleEffect : public ParticleEffect {
		public:
			CircleParticle* particleArray;
			CircleParticleEffect();
			void update(sf::RenderWindow& window);
			void render(sf::RenderWindow& window);
			~CircleParticleEffect();
	};
	class SquareParticleEffect : public ParticleEffect {
	public:
		SquareParticle* particleArray;
		SquareParticleEffect();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~SquareParticleEffect();
	};
	class RectangleParticleEffect : public ParticleEffect {
	public:
		RectangleParticle* particleArray;
		RectangleParticleEffect();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~RectangleParticleEffect();
	};
}

#endif