#ifndef AI_CONTROLLER_H
#define AI_CONTROLLER_H

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
	class AIController
	{
		// Protected accessibility allows direct access for deriving classes
	protected:

	public:
		// Default constructor
		AIController();


		// Our update interface, NOTE it is a pure virtual function
		void update(sf::RenderWindow& window);

		// Our render interface, NOTE it is a pure virtual function
		int sense(const sf::Vector2f& paddlePosition, const sf::Vector2f& ballPosition);

		~AIController();
	};
}

#endif