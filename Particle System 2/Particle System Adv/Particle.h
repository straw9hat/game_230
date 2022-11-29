// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef PARTICLE_H
#define PARTICLE_H

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

	class Particle {
	public:
		int lifeSpan;
	protected:
		bool isAlive;
		sf::Vector2f position;

	public:
		sf::Vector2f velocity;
		Particle();
		void update(sf::RenderWindow& window);
		virtual void render(sf::RenderWindow& window) = 0;
		~Particle();
	};
}

#endif