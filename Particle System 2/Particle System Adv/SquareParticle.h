// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef SQUARE_PARTICLE_H
#define SQUARE_PARTICLE_H

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
#include "Particle.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */

	class SquareParticle : public Particle {
	protected:
		//int lifeSpan;


	public:
		sf::RectangleShape* shape = new sf::RectangleShape();
		SquareParticle();
		void render(sf::RenderWindow& window);
		~SquareParticle();
	};
}

#endif