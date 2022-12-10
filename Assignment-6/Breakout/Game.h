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

 /* Our Includes */
#include "Box.h"
#include "Ball.h"
#include "PlayerController.h"
#include "GameUI.h"
#include "SoundManager.h"
#include "Level.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {
	const int GameWidth = 640;
	const int GameHeight = 640;

	enum GAMESTATE { START, INGAME, GAMEOVER };

	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		int ctr;
		int checker;
		GAMESTATE state;
		// Our game objects
		Box box1;
		Box box2;
		Box box3;
		Box box4;
		Ball ball;
		PlayerController player1;
		GameUI playerScore;
		GameUI Lives;
		GameUI levelIdc;
		SoundManager music;
		Level level;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		void restart();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		// Destructor
		~Game();
	};
}

#endif