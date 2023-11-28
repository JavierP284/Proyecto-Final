#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Bullet.hpp>
std::vector<Bullet*> bullets;

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    // Default constructor is hidden
    Ship() {}

public:
    Ship(sf::IntRect ir) : Sprite()
    {
        _sprite = ir;
        setTexture(spritesheet);
        setTextureRect(_sprite);
    };
    virtual ~Ship() = default;
    virtual void Update(const float &dt) {}
};

class Player : public Ship {
public:
    Player() : Ship(sf::IntRect(135, 0, 40, 32))
    {
        setPosition({gameHeight * .5f, gameHeight - 32.f});
    }

    void Update(const float &dt) override {
        Ship::Update(dt);

        // Mueve a la izquierda
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-80.0f * dt, 0.0f);
        }
        // Mueve a la derecha
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(80.0f * dt, 0.0f);
        }

        // Dispara balas con la barra espaciadora
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet* bullet = new Bullet(getPosition() + sf::Vector2f(0, -16), spritesheet, false);
        bullets.push_back(bullet);
        }

        // Limita la posición vertical para que no baje con el desplazamiento de la ventana
        sf::Vector2f position = getPosition();
        if (position.y > gameHeight - 32.f) {
            setPosition(position.x, gameHeight - 32.f);
        }
    }
};

// Declaración del vector bullets

#endif