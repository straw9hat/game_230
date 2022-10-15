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

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	class Game {
	public:
		/* Protoypes */
		// Constructor
		sf::CircleShape shape;
		Game();
		// Game Loop Programming Pattern Methods
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window, sf::CircleShape obj);
		void render(sf::RenderWindow& window, sf::CircleShape obj);
		// Destructor
		~Game();
	};
}

#endif