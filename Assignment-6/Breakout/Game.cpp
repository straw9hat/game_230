// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>
#include "Random.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), box1(Vector2f(280, 600), Vector2f(80, 20)), box2(Vector2f(-10, 0), Vector2f(10, 640)), box3(Vector2f(0, 70), Vector2f(640, 10)), box4(Vector2f(630, 10), Vector2f(10, 640)), ball(Vector2f(300, 300), Vector2f(30, 30)) {
	// Set our fps to 60
	window.setFramerateLimit(60);
	ctr = -1;
	state = gm::GAMESTATE::START;
	checker = 0;
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	restart();
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

void Game::restart()
{
	music.PlaySFX(3);
	box3.setFillColor(sf::Color::Black);
	playerScore.score = 0;
	Lives.score = 3;
	level.setLevel(1);
	levelIdc.setText("Level 1", sf::Vector2f(20, -10));
	playerScore.setScore(playerScore.score, sf::Vector2f(360, -10));
	Lives.setScore(Lives.score, sf::Vector2f(600, -10));
	state = gm::GAMESTATE::START;
}



// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		// Handle keyboard input to move box 1
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Left) {
				box1.setMovmentDirection(MovementDirection::Up);
			}
			else if (event.key.code == Keyboard::Right) {
				box1.setMovmentDirection(MovementDirection::Down);
			}
		}
		if (event.type == Event::MouseButtonPressed)
		{
			if (state != GAMESTATE::INGAME)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					std::cout << state;
					restart();
					ball.velocity = sf::Vector2f(50, 200);
					state == GAMESTATE::INGAME;
				}
			}
			if (event.mouseButton.button == Mouse::Right)
			{
				std::cout << state;
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Left && box1.getMovementDirection() == MovementDirection::Up) {
				box1.setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::Right && box1.getMovementDirection() == MovementDirection::Down) {
				box1.setMovmentDirection(MovementDirection::None);
			}
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	if (state == gm::GAMESTATE::GAMEOVER)
		restart();
	// Update our boxes (i.e., move them based on the block's specified movement direction)
	box1.update(window, deltaTime);
	ball.update(window, deltaTime);
	level.update(window);

	if (level.checkFinished())
	{
		restart();
		level.reset();
		if (level.getCurrentLevel() == 2)
		{
			level.setLevel(0);
		}
		else
		{
			level.setLevel(level.getCurrentLevel() + 1);
		}
		levelIdc.setText("Level " + level.getCurrentLevel() + 1, sf::Vector2f(20, -10));
	}

	if (state != GAMESTATE::INGAME) {
		//ball.setPosition(sf::Vector2f(box1.getPosition().x + 30, box1.getPosition().y - 30));
	}

	// If the mouse has entered box 1 then color it green
	if (box1.collide(Vector2f(Mouse::getPosition(window)))) {
		box1.setFillColor(Color::Green);
	}
	else {
		box1.setFillColor(Color::White);
	}

	// If the mouse has entered box 2 then color it green
	if (box2.collide(Vector2f(Mouse::getPosition(window)))) {
		box2.setFillColor(Color::Green);
	}
	else {
		box2.setFillColor(Color::White);
	}

	// If box 1 and 2 have collided then turn 1 blue and 2 red
	if (box4.collide(ball.getCollider())) {
		//ball.setFillColor(Color::Blue);
		ball.velocity = ball.velocity - 2 * (ball.velocity.x * -1 + ball.velocity.y * 0) * Vector2f(-1, 0);
		//box2.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	if (box3.collide(ball.getCollider())) {
		//ball.setFillColor(Color::Blue);
		ball.velocity = ball.velocity - 2 * (ball.velocity.x * 0 + ball.velocity.y * -1) * Vector2f(0, -1);
		//box2.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	if (box2.collide(ball.getCollider())) {
		//ball.setFillColor(Color::Blue);
		ball.velocity = (ball.velocity - 2 * (ball.velocity.x * 1 + ball.velocity.y * 0) * Vector2f(1, 0));
		//box2.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	if (box1.collide(ball.getCollider())) {
		//ball.setFillColor(Color::Blue);
		ball.velocity = (ball.velocity - 2 * (ball.velocity.x * 0 + ball.velocity.y * 1) * Vector2f(0, 1));
		//box1.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	for (int i = 0; i < 8; i++)
	{
			if (ball.collide(level.bricks[i]->getCollider()))
			{
				if (ball.getPosition().x < level.bricks[i]->getPosition().x && ball.getPosition().y < level.bricks[i]->getPosition().y)
				{
					ball.velocity = ball.velocity - 2 * (ball.velocity.x * 0 + ball.velocity.y * -1) * Vector2f(0, -1);
				}
				else if (ball.getPosition().x < level.bricks[i]->getPosition().x && ball.getPosition().y > level.bricks[i]->getPosition().y)
				{
					ball.velocity = ball.velocity - 2 * (ball.velocity.x * -1 + ball.velocity.y * 0) * Vector2f(-1, 0);
				}
				else if (ball.getPosition().x > level.bricks[i]->getPosition().x && ball.getPosition().y < level.bricks[i]->getPosition().y)
				{
					ball.velocity = (ball.velocity - 2 * (ball.velocity.x * 1 + ball.velocity.y * 0) * Vector2f(1, 0));
				}
				else if (ball.getPosition().x > level.bricks[i]->getPosition().x && ball.getPosition().y > level.bricks[i]->getPosition().y)
				{
					ball.velocity = (ball.velocity - 2 * (ball.velocity.x * 0 + ball.velocity.y * 1) * Vector2f(0, 1));
				}
				level.getBrick(i)->setHealth(level.getBrick(i)->getHealth() - 1);
				if (level.getBrick(i)->getHealth() == 0)
				{
					level.setBricksBroken(level.getBricksBroken() + 1);
				}
				if (level.getBrick(i)->getHealth() == 1)
				{
					level.bricks[i]->body.setFillColor(sf::Color::White);
				}
				playerScore.score += 5;
				playerScore.setScore(playerScore.score, sf::Vector2f(360, -10));
			}
		
	}
	if (ball.getPosition().y > 640)
	{
		ctr = 120;
		state = GAMESTATE::GAMEOVER;
		ball.setPosition(sf::Vector2f(box1.getPosition().x + 30, box1.getPosition().y - 30));
		//ball.velocity = sf::Vector2f(0, 0);
		music.PlaySFX(2);
		Lives.score--;
		Lives.setScore(Lives.score, sf::Vector2f(600, -10));
		if (Lives.score == 0)
			restart();
	}
	
	if (ctr == 0)
	{
		sf::Vector2f vel[4] = { sf::Vector2f(200,40), sf::Vector2f(-200,40), sf::Vector2f(200,-40), sf::Vector2f(-200,-40) };
		ball.velocity = vel[Random::Range(0, 3)];
		ctr = -1;
		//winner.string = "";
		//winner.setText(winner.string, sf::Vector2f(200, 360));
	}
	if (ctr > 0)
		ctr--;
	if (playerScore.score >= 3)
	{
		//winner.string = "Player wins!";
		//winner.setText(winner.string, sf::Vector2f(200, 360));
		state = gm::GAMESTATE::GAMEOVER;
		checker = 1;
		restart();
	}
	
	if (checker == 1) {
		std::cout << "Player wins!";
		checker = 0;
	}
	
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	// This clears the window at the beginning of every frame
	window.clear();

	// Draw our boxes
	box1.render(window, deltaTime);
	box2.render(window, deltaTime);
	ball.render(window, deltaTime);
	playerScore.render(window);
	Lives.render(window);
	levelIdc.render(window);
	level.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}