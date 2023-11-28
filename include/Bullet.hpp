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


Bullet::Bullet(const sf::Vector2f& pos, const sf::Texture& texture, const bool mode) : _mode(mode) {
    setTexture(texture);
    setPosition(pos);
}

void Bullet::Update(const float& dt) {
    move(0, dt * 200.0f * (_mode ? -1.0f : 1.0f));  // Cambiado el sentido para que las balas del jugador suban
}
