#ifndef NAVE_HPP
#define NAVE_HPP

#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Bullet.hpp>


class Nave : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    // Default constructor is hidden
    Nave() {}

public:
    Nave(sf::IntRect ir) : Sprite()
    {
        _sprite = ir;
        setTexture(spritesheet);
        setTextureRect(_sprite);
    };
    virtual ~Nave() = default;
    virtual void Update(const float &dt) {}
};
#endif