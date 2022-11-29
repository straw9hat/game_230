#ifndef GAME_U_I_H
#define GAME_U_I_H

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
	class GameUI
	{
		// Protected accessibility allows direct access for deriving classes
	protected:
		
	public:
		// Default constructor
		GameUI();


		// Our update interface, NOTE it is a pure virtual function
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;

		// Our render interface, NOTE it is a pure virtual function
		virtual void render(sf::RenderWindow& window, float deltaTime) = 0;

		// Our position getter, NOTE the const reference return and marking the method itself const
		virtual const sf::Vector2f& getScore() const;

		// Our position setter, NOTE the pass by const reference
		virtual void setScore(const sf::Vector2f& position);

		~GameUI();
	};
}

#endif