// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"
#include <iostream>
#include "Random.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), box1(Vector2f(20, 200), Vector2f(20, 80)), box2(Vector2f(600, 200), Vector2f(20, 80)), box3(Vector2f(0, 0), Vector2f(640, 10)), box4(Vector2f(0, 630), Vector2f(640, 10)), ball(Vector2f(300, 300), Vector2f(50, 50)) {
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
	playerScore.score = 0;
	aiScore.score = 0;
	playerScore.setScore(playerScore.score, sf::Vector2f(200, 40));
	aiScore.setScore(aiScore.score, sf::Vector2f(400, 40));
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
			if (event.key.code == Keyboard::Up) {
				box1.setMovmentDirection(MovementDirection::Up);
			}
			else if (event.key.code == Keyboard::Down) {
				box1.setMovmentDirection(MovementDirection::Down);
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Up && box1.getMovementDirection() == MovementDirection::Up) {
				box1.setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::Down && box1.getMovementDirection() == MovementDirection::Down) {
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
	box2.update(window, deltaTime);
	ball.update(window, deltaTime);

	if (aI.sense(ball.getPosition(), box2.getPosition()) == 1)
	{
		box2.setMovmentDirection(MovementDirection::Up);
	}
	else if (aI.sense(ball.getPosition(), box2.getPosition()) == -1)
	{
		box2.setMovmentDirection(MovementDirection::Down);
	}
	else
	{
		box2.setMovmentDirection(MovementDirection::None);
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
		ball.velocity = ball.velocity - 2 * (ball.velocity.x * 0 + ball.velocity.y * 1) * Vector2f(0, 1);
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
		ball.velocity = (ball.velocity - 2 * (ball.velocity.x * 1 + ball.velocity.y * 0) * Vector2f(1, 0)) * 1.02f;
		//box2.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	if (box1.collide(ball.getCollider())) {
		//ball.setFillColor(Color::Blue);
		ball.velocity = (ball.velocity - 2 * (ball.velocity.x * -1 + ball.velocity.y * 0) * Vector2f(-1, 0)) * 1.02f;
		//box1.setFillColor(Color::Red);
		music.PlaySFX(0);
	}
	if (ball.getPosition().x < 0)
	{
		ctr = 120;
		ball.setPosition(sf::Vector2f(300, 300));
		ball.velocity = sf::Vector2f(0, 0);
		aiScore.score++;
		aiScore.setScore(aiScore.score, sf::Vector2f(400, 40));
		music.PlaySFX(2);
	}
	if (ball.getPosition().x > 590)
	{
		ctr = 120;
		ball.setPosition(sf::Vector2f(300, 300));
		ball.velocity = sf::Vector2f(0, 0);
		music.PlaySFX(1);
	}
	if (ctr == 0)
	{
		sf::Vector2f vel[4] = { sf::Vector2f(200,40), sf::Vector2f(-200,40), sf::Vector2f(200,-40), sf::Vector2f(-200,-40) };
		ball.velocity = vel[Random::Range(0, 3)];
		ctr = -1;
		winner.string = "";
		winner.setText(winner.string, sf::Vector2f(200, 360));
	}
	if (ctr > 0)
		ctr--;
	if (playerScore.score >= 3) 
	{
		winner.string = "Player wins!";
		winner.setText(winner.string, sf::Vector2f(200, 360));
		state = gm::GAMESTATE::GAMEOVER;
		checker = 1;
		restart();
	}
	else if (aiScore.score >= 3)
	{
		//std::cout << "here";
		winner.string = "AI wins!";
		winner.setText(winner.string, sf::Vector2f(200, 360));
		state = gm::GAMESTATE::GAMEOVER;
		checker = 2;
		restart();
	}
	if (checker == 1) {
		std::cout << "Player wins!";
		checker = 0;
	}
	else if (checker == 2) {
		std::cout << "AI wins!";
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
	aiScore.render(window);
	winner.render(window);

	// Display the window buffer for this frame
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}