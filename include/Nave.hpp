#ifndef NAVE_HPP
#define NAVE_HPP

#include <SFML/Graphics.hpp>

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
    virtual void Pilotar(const float &dt) {}
};
#endif