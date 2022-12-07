#include "GameUI.h"
#include <iostream>

using namespace sf;
using namespace gm;

// Default constructor
GameUI::GameUI() {
	score = 0;
	string = "";
	font.loadFromFile("pixel.otf");
	text.setFont(font);
	text.setCharacterSize(72);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
}



// Our position getter, NOTE the const reference return and marking the method itself const
const std::string& GameUI::getScore() const {
	//return position;
	return text.getString();
}

// Our position setter, takes a Vector2f by const reference
void GameUI::setScore(int score, sf::Vector2f position) {
	text.setString(std::to_string(score));
	text.setPosition(position);
}

const std::string& GameUI::getText() const {
	return text.getString();
}

void GameUI::setText(std::string string, sf::Vector2f position) {
	text.setString(string);
	text.setPosition(position);

}

void GameUI::update(sf::RenderWindow& window)
{

}
void GameUI::render(sf::RenderWindow& window)
{
	window.draw(text);
}

GameUI::~GameUI() {}