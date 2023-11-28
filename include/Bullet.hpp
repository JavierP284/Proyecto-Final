// En Bullet.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
    Bullet(const sf::Vector2f& pos, const sf::Texture& texture, const bool mode);
    void Update(const float& dt);
    ~Bullet() = default;

protected:
    // false=player bullet, true=Enemy bullet
    bool _mode;
};

// En Bullet.cpp
#include "Bullet.hpp"

Bullet::Bullet(const sf::Vector2f& pos, const sf::Texture& texture, const bool mode) : _mode(mode) {
    setTexture(texture);

    // Establece el rectángulo de textura según el modo (jugador o enemigo)
    sf::IntRect textureRect = _mode ? sf::IntRect(250, 0, 5, 5) : sf::IntRect(250, 0, 10, 30);
    setTextureRect(textureRect);

    setPosition(pos);
}

void Bullet::Update(const float& dt) {
    move(0, dt * -200.0f * (_mode ? -1.0f : 1.0f));
}