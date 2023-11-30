#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Bala.hpp>
#include <Nave.hpp>
std::vector<Bala*> balas;

class Jugador : public Nave {
private:
    float shootCooldown;  // Tiempo de enfriamiento entre disparos en segundos
    float timeSinceLastShoot;  // Tiempo transcurrido desde el último disparo

public:
    Jugador() : Nave(sf::IntRect(135, 0, 40, 40)), shootCooldown(0.5f), timeSinceLastShoot(0.0f) {
        setPosition({gameWidth * 0.5f, gameHeight - 32.0f});
    }

    void Update(const float &dt) override {
        Nave::Update(dt);

        // Actualiza el tiempo transcurrido desde el último disparo
        timeSinceLastShoot += dt;

        // Mueve a la izquierda
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-80.0f * dt, 0.0f);
        }

        // Mueve a la derecha
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(80.0f * dt, 0.0f);
        }

        // Dispara balas con la barra espaciadora si ha pasado el tiempo de enfriamiento
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceLastShoot >= shootCooldown) {
            Bala* bullet = new Bala(getPosition() + sf::Vector2f(0, -16), spritesheet, false);
            balas.push_back(bullet);

            // Reinicia el tiempo desde el último disparo
            timeSinceLastShoot = 0.0f;
        }

        // Limita la posición vertical para que no baje con el desplazamiento de la ventana
        sf::Vector2f position = getPosition();
        if (position.y > gameHeight - 32.f) {
            setPosition(position.x, gameHeight - 32.f);
        }
    }
};
