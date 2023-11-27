#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "Ship.hpp"
#include "Game.hpp"
#include "Invader.hpp"
#include "Bullet.hpp" // Assuming you have a Bullet class

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
sf::Texture spritesheet;
sf::Texture backgroundTexture;
std::vector<Ship*> ships; // Assuming you have a vector to store ships

bool Invader::direction = true;
float Invader::speed = 5.0f;

void Load() {
    // Loading textures, initializing ships, and adding them to the vector
    if (!spritesheet.loadFromFile("assets/images/SpritesheetSW2.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    if (!backgroundTexture.loadFromFile("assets/images/Background.jpg")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    for (int r = 0; r < invaders_rows; ++r) {
        sf::IntRect rect(0, 0, 38, 32);
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
    // Drawing ships
    for (const auto& s : ships) {
        window.draw(*s);
    }
}

void Update(float dt) {
    // Updating ships
    for (auto& s : ships) {
        s->Update(dt);
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

        // Handle player input and update
        ships.back()->Update(dt);

        // Fire bullet when space key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            ships.back()->FireBullet();
        }

        // Update all ships, including bullets
        Update(dt);

        window.clear();
        Render();
        window.display();
    }

    return 0;
}
