#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

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
	class SoundManager
	{
		// Protected accessibility allows direct access for deriving classes
	protected:
		sf::SoundBuffer* buffer;
		sf::Sound sound;
	public:
		// Default constructor
		SoundManager();


		void PlaySFX(int type);

		~SoundManager();
	};
}

#endif