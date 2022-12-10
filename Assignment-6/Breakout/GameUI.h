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
	public:
		int score;
		std::string string;
		// Protected accessibility allows direct access for deriving classes
	protected:
		sf::Font font;
		sf::Text text;
	public:
		// Default constructor
		GameUI();


		// Our update interface
		void update(sf::RenderWindow& window);

		// Our render interfac
		void render(sf::RenderWindow& window);

		// Our position getter, NOTE the const reference return and marking the method itself const
		virtual const std::string& getScore() const;

		// Our position setter, NOTE the pass by const reference
		virtual void setScore(int score, sf::Vector2f position);

		virtual const std::string& getText() const;

		virtual void setText(std::string text, sf::Vector2f position);

		~GameUI();
	};
}

#endif