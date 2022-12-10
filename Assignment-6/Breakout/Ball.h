#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

namespace gm {
    // Box movement speed


    class Ball :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
    public:
        sf::Vector2f velocity;
        Ball(const sf::Vector2f& position, const sf::Vector2f& size);

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);
    };
}

#endif