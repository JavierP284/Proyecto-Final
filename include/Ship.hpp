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