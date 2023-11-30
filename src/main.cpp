#include <SFML/Graphics.hpp>
#include <iostream>
#include <Ship.hpp>
#include <Game.hpp>
#include <Invader.hpp>
#include <Bullet.hpp>
#include <Jugador.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
sf::Texture spritesheet;
sf::Sprite invader;
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

// Vector de balas
bool Invader::direction = true;
float Invader::speed = 5.0f;

// Vector de naves
void Load() {
    if (!backgroundTexture.loadFromFile("assets/images/background.jpg")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }
    // Establece la textura para el sprite de fondo
    backgroundSprite.setTexture(backgroundTexture);

    if (!spritesheet.loadFromFile("assets/images/SpritesheetSW2.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

    for (int r = 0; r < invaders_rows; ++r) {
        sf::IntRect rect(0, 0, 38, 40);
        for (int c = 0; c < invaders_columns; ++c) {
            sf::Vector2f position(100.0f + c * 40.0f, 100.0f + r * 40.0f);
            Invader* inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }

    Jugador* jugador = new Jugador();
    ships.push_back(jugador);
}

void Render() {
    window.draw(backgroundSprite);

    for (const auto& s : ships) {
        window.draw(*s);
    }

    for (const auto& bullet : bullets) {
        window.draw(*bullet);
    }
}

void Update(float dt) {
    // Actualizar las naves y las balas
    for (auto it = ships.begin(); it != ships.end(); ) {
    (*it)->Update(dt);

    // Verificar si es una bala y debe ser destruida
    Bullet* bullet = dynamic_cast<Bullet*>(*it);
    if (bullet && bullet->ShouldBeDestroyed()) {
        delete *it;
        it = ships.erase(it);
    } else {
        ++it;
    }
}

    // Eliminar balas después del bucle de naves
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        (*it)->Update(dt);
        if ((*it)->ShouldBeDestroyed()) {
            delete *it;
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    Load();

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        Update(dt);

        window.clear();
        Render();
        window.display();
    }

    // Limpiar la memoria al salir
    for (auto& s : ships) {
        delete s;
    }

    for (auto& bullet : bullets) {
        delete bullet;
    }

    return 0;
}
