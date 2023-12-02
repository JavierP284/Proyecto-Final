// Jugador.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <Bala.hpp>
#include <Nave.hpp>
#include <vector>

class Jugador : public Nave {
private:
    float shootCooldown;
    float timeSinceLastShoot;
    std::vector<Bala*>& balas;  // Add a reference to the balas vector

public:
    // Modify the constructor to take the balas vector as an argument
    Jugador(std::vector<Bala*>& balas) : Nave(sf::IntRect(135, 0, 40, 40)), shootCooldown(0.5f), timeSinceLastShoot(0.0f), balas(balas) {
        setPosition({ventanaWidth * 0.5f, ventanaHeight - 32.0f});
    }

    // Modify the Pilotar method to add the bullets to the balas vector
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