#pragma once
#include <SFML/Graphics.hpp>
#include <Game.hpp>

class Ship : public sf::Sprite
{
protected:
    sf::IntRect _sprite;
    // Default constructor is hidden
    Ship() {}

public:
    // Constructor that takes a sprite
    Ship(sf::IntRect ir) : Sprite()
    {
        _sprite = ir;
        setTexture(spritesheet);
        setTextureRect(_sprite);
    };
    // Pure virtual deconstructor -- makes this an abstract class
    virtual ~Ship() = default;
    // Update, virtual so can be overrided, but not pure virtual
    virtual void Update(const float &dt){}
};

class Player : public Ship {
public:
    Player() : Ship(sf::IntRect(90, 0, 20, 32))
    {
        setPosition({gameHeight * .5f, gameHeight - 32.f});
    }

    void Update(const float &dt) override {
        Ship::Update(dt);
        // Mueve a la izquierda
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-50.0f * dt, 0.0f);
        }
        // Mueve a la derecha
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(50.0f * dt, 0.0f);
        }

        // Limita la posición vertical para que no baje con el desplazamiento de la ventana
        sf::Vector2f position = getPosition();
        if (position.y > gameHeight - 32.f) {
            setPosition(position.x, gameHeight - 32.f);
        }
    }
};