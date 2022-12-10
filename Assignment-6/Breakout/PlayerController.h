#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 // Use our gm namespace for all our defined classes
namespace gm {
	// Our abstract GameObject class that defines the interface for all objects that appear in our games
	class PlayerController
	{
		// Protected accessibility allows direct access for deriving classes
	protected:

	public:
		// Default constructor
		PlayerController();


		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window);

		// Our render interface, NOTE it is a pure virtual function
		virtual void handleInput();

		~PlayerController();
	};
}

#endif