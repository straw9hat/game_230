// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef CIRCLE_PARTICLE_EFFECT_H
#define CIRCLE_PARTICLE_EFFECT_H

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
#include "ParticleEffect.h"
#include "CircleParticle.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */

	class CircleParticleEffect : public ParticleEffect {
	private:
		CircleParticle* particleArray;
	public:
		CircleParticleEffect();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~CircleParticleEffect();
	};
}

#endif