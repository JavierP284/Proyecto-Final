#pragma once
#include <SFML/Graphics.hpp>
#include <Bala.hpp>
#include <Nave.hpp>

extern std::vector<Bala*> balas;

class Jugador : public Nave {
private:
    float shootCooldown;
    float timeSinceLastShoot;

public:
    Jugador() : Nave(sf::IntRect(135, 0, 40, 40)), shootCooldown(0.5f), timeSinceLastShoot(0.0f) {
        setPosition({ventanaWidth * 0.5f, ventanaHeight - 32.0f});

        // Cambia _mode a true para que la bala se mueva hacia arriba
        Bala* bullet = new Bala(getPosition() + sf::Vector2f(0, -16), spritesheet, false);
        bullet->setTexture(spritesheet);
        balas.push_back(bullet);
    }

    void Pilotar(const float& dt) override {
        Nave::Pilotar(dt);

        timeSinceLastShoot += dt;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-80.0f * dt, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(80.0f * dt, 0.0f);
        }

        // Crear bala al presionar espacio si ha pasado el tiempo de enfriamiento
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceLastShoot >= shootCooldown) {
            Bala* bullet = new Bala(getPosition() + sf::Vector2f(0, -16), spritesheet, false);
            bullet->setTexture(spritesheet);
            balas.push_back(bullet);
            timeSinceLastShoot = 0.0f;
        }

        // Limitar la posición vertical para que no baje con el desplazamiento de la ventana
        sf::Vector2f position = getPosition();
        if (position.y > ventanaHeight - 32.f) {
            setPosition(position.x, ventanaHeight - 32.f);
        }
    }
};