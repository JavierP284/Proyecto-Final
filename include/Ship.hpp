#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Bullet.hpp>


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
#endif