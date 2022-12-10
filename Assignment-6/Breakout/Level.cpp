#include "Level.h"
#include <iostream>

using namespace sf;
using namespace gm;

Level::Level() {
	currentLevel = 0;
	bricksBroken = 0;
	totalBricks = 0;
	//std::cout << "total bricks: "<< sizeof(bricks) / sizeof(bricks[0]);
}

void Level::update(sf::RenderWindow& window) {
	for (int i = 0; i < sizeof(bricks) / sizeof(bricks[0]); i++) {
		if (bricks[i] != nullptr && bricks[i]->getAlive())
		{
			bricks[i]->update(window);
		}
	}
}

void Level::render(sf::RenderWindow& window) {
	for (int i = 0; i < sizeof(bricks) / sizeof(bricks[0]); i++) {
		if (bricks[i] != nullptr && bricks[i]->getAlive())
		{
			bricks[i]->render(window);
		}
	}
}

Brick* Level::getBrick(int index) {
	return bricks[index];
}

const int Level::getCurrentLevel() {
	return currentLevel;
}

const int Level::getBricksBroken() {
	return bricksBroken;
}

const bool Level::checkFinished() {
	if (totalBricks - bricksBroken == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Level::setBricksBroken(int num) {
	bricksBroken = num;
}

void Level::setLevel(int level) {
	currentLevel = level;
	totalBricks = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 8; j++)
		{
				if (arr[level][i][j] == 0)
				{
					bricks[(10 * i) + j] = nullptr;
				}
				else if (arr[level][i][j] == 1)
				{
					bricks[(10 * i) + j] = new Brick(Vector2f(80.0f * j, (20.0f * i) + 80.0f), Vector2f(80.0f, 20.0f), &broken_brick);
					totalBricks++;
				}
				else if (arr[level][i][j] == 2)
				{
					bricks[(10 * i) + j] = new Brick(Vector2f(80.0f * j, (20.0f * i) + 80.0f), Vector2f(80.0f, 20.0f), &normal_brick);
					totalBricks++;
				}
			

		}
	}
	std::cout << "total bricks: " << totalBricks;
}

void Level::reset() {
	bricksBroken = 0;
	totalBricks = 0;
	for (int i = 0; i < sizeof(bricks) / sizeof(bricks[0]); i++) {
		if (bricks[i] != nullptr)
		{
			delete bricks[i];
		}
	}
}

Level::~Level() {
	for (int i = 0; i < sizeof(bricks) / sizeof(bricks[0]); i++) {
		if (bricks[i] != nullptr)
		{
			delete bricks[i];
		}
	}
}