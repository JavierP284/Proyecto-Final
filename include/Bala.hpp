#pragma once
#include <SFML/Graphics.hpp>

class Bala : public sf::Sprite {
public:
    Bala(const sf::Vector2f& pos, const sf::Texture& texture, const bool mode);
    void Desaparecer(const float& dt);
    ~Bala() = default;
    bool ShouldBeDestroyed() const;

protected:
    bool _mode;
    float _lifetime;  // Tiempo de vida actual de la bala
    float _maxLifetime;  // Tiempo máximo de vida de la bala (en segundos)
};

Bala::Bala(const sf::Vector2f& pos, const sf::Texture& texture, const bool mode) : _mode(mode), _lifetime(0.0f), _maxLifetime(5.0f) {
    setTexture(texture);

    // Establece el rectángulo de textura según el modo (jugador o enemigo)
    sf::IntRect textureRect = _mode ? sf::IntRect(250, 0, 40, 32) : sf::IntRect(30, 0, 40, 32);
    setTextureRect(textureRect);

    setPosition(pos);
}



void Bala::Desaparecer(const float& dt) {
    move(0, dt * -200.0f * (_mode ? -1.0f : 1.0f));

    // Actualiza el tiempo de vida
    _lifetime += dt;
}

bool Bala::ShouldBeDestroyed() const {
    return _lifetime >= _maxLifetime;
}