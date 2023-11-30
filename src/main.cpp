#include <SFML/Graphics.hpp>
#include <iostream>
#include <Nave.hpp>
#include <Game.hpp>
#include <Invader.hpp>
#include <Bala.hpp>
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
            naves.push_back(inv);
        }
    }

    Jugador* jugador = new Jugador();
    naves.push_back(jugador);
}

void Render() {
    window.draw(backgroundSprite);

    for (const auto& s : naves) {
        window.draw(*s);
    }

    for (const auto& bala : balas) {
        window.draw(*bala);
    }
}

void Update(float dt) {
    // Actualizar las naves y las balas
    for (auto it = naves.begin(); it != naves.end(); ) {
    (*it)->Update(dt);

    // Verificar si es una bala y debe ser destruida
    Bala* bala = dynamic_cast<Bala*>(*it);
    if (bala && bala->ShouldBeDestroyed()) {
        delete *it;
        it = naves.erase(it);
    } else {
        ++it;
    }
}

    // Eliminar balas después del bucle de naves
    for (auto it = balas.begin(); it != balas.end(); ) {
        (*it)->Update(dt);
        if ((*it)->ShouldBeDestroyed()) {
            delete *it;
            it = balas.erase(it);
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
    for (auto& s : naves) {
        delete s;
    }

    for (auto& bala : balas) {
        delete bala;
    }

    return 0;
}
