#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

//Global Variables
int BrushSize = 25;
sf::Color BrushColor(0, 255, 0, 255);
bool flag = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(BrushSize);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Mouse::Left) {
				flag = true;
			}
			else if (event.key.code == sf::Mouse::Right) {
				flag = false;
			}
			switch (event.key.code)
			{
				case sf::Keyboard::Num1:
					BrushColor.r = 255;
					BrushColor.g = 0;
					BrushColor.b = 0;
					break;
				case sf::Keyboard::Num2:
					BrushColor.r = 0;
					BrushColor.g = 255;
					BrushColor.b = 0;
					break;
				case sf::Keyboard::Num3:
					BrushColor.r = 0;
					BrushColor.g = 0;
					BrushColor.b = 255;
					break;
			}
			if (event.key.code == sf::Keyboard::Left && BrushColor.a - 25.5 > 0)
			{
				BrushColor.a -= 25.5;
			}
			else if (event.key.code == sf::Keyboard::Right && BrushColor.a + 25.5 < 255)
			{
				BrushColor.a += 25.5;
			}
			if (event.key.code == sf::Keyboard::Down && BrushSize - 5 > 0)
			{
				BrushSize -= 5;
			}
			else if (event.key.code == sf::Keyboard::Up && BrushSize + 5 < 50)
			{
				BrushSize += 5;
			}
			if (event.key.code == sf::Keyboard::Space) {
				sf::Texture texture;
				texture.create(window.getSize().x, window.getSize().y);
				texture.update(window);
				if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
				{
					std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
				}
			}
		}
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(2 * BrushSize, 2 * BrushSize));
		shape.setFillColor(BrushColor);
		//window.clear();
		if (flag) {
			shape.setPosition(sf::Mouse::getPosition(window).x - BrushSize, sf::Mouse::getPosition(window).y - BrushSize);
			window.draw(shape);
		}
		window.display();
	}
	return 0;
}