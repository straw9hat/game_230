#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace std;

//Global Variables
int BrushSize = 25;   //initial brush size
sf::Color BrushColor(0, 255, 0, 255);  //initial brush colour
bool flag = false;

int main()
{
	//initialize window size of console app
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(BrushSize);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//code to paint or stop on right and left mouse clicks
			if (event.key.code == sf::Mouse::Left) {
				flag = true;
			}
			else if (event.key.code == sf::Mouse::Right) {
				flag = false;
			}
			//block to change colour on key press
			switch (event.key.code)
			{
				case sf::Keyboard::Num1:
				case sf::Keyboard::Numpad1:
					BrushColor.r = 255;
					BrushColor.g = 255;
					BrushColor.b = 255;
					cout << "Brush colour changed to white" << endl;
					break;
				case sf::Keyboard::Num2:
				case sf::Keyboard::Numpad2:
					BrushColor.r = 255;
					BrushColor.g = 0;
					BrushColor.b = 0;
					cout << "Brush colour changed to red" << endl;
					break;
				case sf::Keyboard::Num3:
				case sf::Keyboard::Numpad3:
					BrushColor.r = 0;
					BrushColor.g = 0;
					BrushColor.b = 255;
					cout << "Brush colour changed to blue" << endl;
					break;
				case sf::Keyboard::Num4:
				case sf::Keyboard::Numpad4:
					BrushColor.r = 255;
					BrushColor.g = 255;
					BrushColor.b = 0;
					cout << "Brush colour changed to yellow" << endl;
					break;
				case sf::Keyboard::Num5:
				case sf::Keyboard::Numpad5:
					BrushColor.r = 0;
					BrushColor.g = 255;
					BrushColor.b = 255;
					cout << "Brush colour changed to cyan" << endl;
					break;
				case sf::Keyboard::Num6:
				case sf::Keyboard::Numpad6:
					BrushColor.r = 255;
					BrushColor.g = 0;
					BrushColor.b = 255;
					cout << "Brush colour changed to magenta" << endl;
					break;
				case sf::Keyboard::Num7:
				case sf::Keyboard::Numpad7:
					BrushColor.r = 128;
					BrushColor.g = 0;
					BrushColor.b = 0;
					cout << "Brush colour changed to maroon" << endl;
					break;
				case sf::Keyboard::Num8:
				case sf::Keyboard::Numpad8:
					BrushColor.r = 0;
					BrushColor.g = 255;
					BrushColor.b = 0;
					cout << "Brush colour changed to green" << endl;
					break;
				case sf::Keyboard::Num9:
				case sf::Keyboard::Numpad9:
					BrushColor.r = 128;
					BrushColor.g = 0;
					BrushColor.b = 128;
					cout << "Brush colour changed to purple" << endl;
					break;
				case sf::Keyboard::Num0:
				case sf::Keyboard::Numpad0:
					BrushColor.r = 0;
					BrushColor.g = 0;
					BrushColor.b = 0;
					cout << "Brush colour changed to black" << endl;
					break;
			}
			//block to change opacity on key press- left and right arrows
			if (event.key.code == sf::Keyboard::Left && BrushColor.a - 25.5 > 0)
			{
				BrushColor.a -= 25.5;
				cout << "Brush opacity reduced" << endl;
			}
			else if (event.key.code == sf::Keyboard::Right && BrushColor.a + 25.5 < 255)
			{
				BrushColor.a += 25.5;
				cout << "Brush opacity increased" << endl;
			}
			//block to change radius on key press- up and down arrows
			if (event.key.code == sf::Keyboard::Down && BrushSize - 5 > 0)
			{
				BrushSize -= 5;
				cout << "Brush radius reduced" << endl;
			}
			else if (event.key.code == sf::Keyboard::Up && BrushSize + 5 < 50)
			{
				BrushSize += 5;
				cout << "Brush radius increased" << endl;
			}
			//take a screenshot
			if (event.key.code == sf::Keyboard::Space) {
				sf::Texture texture;
				texture.create(window.getSize().x, window.getSize().y);
				texture.update(window);
				if (texture.copyToImage().saveToFile("Jolly Roger.png"))
				{
					cout << "Screenshot saved to Jolly Roger.png" << endl;
				}
			}
		}
		//initialiaze shape
		sf::CircleShape shape(BrushSize);
		shape.setFillColor(BrushColor);
		//window.clear();
		//center mouse pointer
		shape.setPosition(sf::Mouse::getPosition(window).x - BrushSize, sf::Mouse::getPosition(window).y - BrushSize);
		if (flag) {
			window.draw(shape);
		}
		window.display();
	}
	return 0;
}