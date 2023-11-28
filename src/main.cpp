#include <SFML/Graphics.hpp>
#include <iostream>
#include <Ship.hpp>
#include <Game.hpp>
#include <Invader.hpp>
#include <Bullet.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
sf::Texture spritesheet;
sf::Sprite invader;
 // Definición del vector bullets

bool Invader::direction = true;
float Invader::speed = 5.0f;

// Define the ships vector for Invader
void Load() {
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

    Player* player = new Player();
    ships.push_back(player);
}

void Render() {
    for (const auto& s : ships) {
        window.draw(*s);
    }

    for (const auto& bullet : bullets) {
        window.draw(*bullet);
    }
}

void Update(float dt) {
    for (auto& s : ships) {
        s->Update(dt);
    }
    
    for (auto& bullet : bullets) {
        bullet->Update(dt);
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

    return 0;
}