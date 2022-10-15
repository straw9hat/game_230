#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include<fstream>
using namespace std;



// Protoypes
void setup(sf::RenderWindow& window);
void handleInput(sf::RenderWindow& window, sf::Event& e);
void update(sf::RenderWindow& window);
void render(sf::RenderWindow& window);

//Global variables
sf::RectangleShape mask;
int arrLevel[9][16];
sf::Texture texture[20];
int selectedSprite;
sf::Sprite sprite;
int label = 100;
bool flag1 = false;
bool flag2 = false;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1120, 630), "SFML works!");

    setup(window);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            handleInput(window, event);
            
        }

        update(window);

        render(window);
        
    }

    return 0;
}


void setup(sf::RenderWindow& window)
{
    mask = sf::RectangleShape(sf::Vector2f(70, 70));
    mask.setFillColor(sf::Color::Black);

    //initialize level to store the tile map

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            arrLevel[i][j] = -1;
        }
    }

    //load all the textures
    cout << sizeof(texture);
    for (int i = 0; i < 20; i++)
    {
        if (!texture[i].loadFromFile("Assets/Homework 2 Tilesets/Platformer/70x70/Platformer-" + to_string(i) + ".png"))
            cout << "Can not locate a texture!" << endl;
    }
    selectedSprite = 0;
    sprite.setTexture(texture[selectedSprite]);
}

void update(sf::RenderWindow& window)
{

}

void handleInput(sf::RenderWindow& window, sf::Event& event)
{
    if (event.type == sf::Event::Closed)
        window.close();
    //screenshot
    if (event.key.code == sf::Keyboard::Space) {
        sf::Texture screenShot;
        screenShot.create(window.getSize().x, window.getSize().y);
        screenShot.update(window);
        if (screenShot.copyToImage().saveToFile("Homework 2 Screenshot.png"))
        {
            std::cout << "Screenshot saved to Homework 2 Screenshot.png" << std::endl;
        }
    }

    //save level in a file
    if (event.key.code == sf::Keyboard::S)
    {
        ofstream fout("level.txt");
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                fout << arrLevel[i][j] << " ";
            }
            fout << endl;
        }
    }

    //get mouse pointer location
    int mouseX = (sf::Mouse::getPosition(window).x / 70) * 70;
    int mouseY = (sf::Mouse::getPosition(window).y / 70) * 70;
    
    if (label!= mouseX * 9 + mouseY)
    {
        //sprite.setPosition(mouseX, mouseY);
        //flag1 = true;
        //mask.setPosition(int(label/16)*70,int(label%16)*70);
    }
    if (event.key.code == sf::Mouse::Left)
    {
        //cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
        sprite.setPosition(mouseX, mouseY);
        arrLevel[mouseX/70][mouseY/70] = selectedSprite;
    }

    //erase
    if (event.key.code == sf::Mouse::Right)
    {
        //cout << "delete attempted" << endl;
        mask.setPosition(mouseX, mouseY);
    }

    //stash it later
    if (event.key.code == sf::Mouse::Middle)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cout << arrLevel[i][j] << "  ";
            }
            cout << endl;
        }
    }

    //switch sprites
    if (event.key.code == sf::Keyboard::Up)
    {
        cout << sizeof(texture) / sizeof(sf::Texture);
        (selectedSprite >= sizeof(texture)/sizeof(sf::Texture) - 1) ? selectedSprite = 0 : selectedSprite++;
        sprite.setTexture(texture[selectedSprite]);
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        (selectedSprite <= 0) ? selectedSprite = sizeof(texture)/ sizeof(sf::Texture) - 1 : selectedSprite--;
        sprite.setTexture(texture[selectedSprite]);
    }

    label = mouseX * 9 + mouseY;
    //cout << mouseX << " " << mouseY << endl;
}

void render(sf::RenderWindow& window)
{
    //window.clear();
    window.draw(sprite);
    window.draw(mask);
    window.display();
}