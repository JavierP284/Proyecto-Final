#include <SFML/Graphics.hpp>
#include <iostream>
#include <Ship.hpp>
#include <Game.hpp>

std::vector<Ship*> ships;
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
sf::Texture spritesheet;
sf::Sprite invader;

void Load() {
    if (!spritesheet.loadFromFile("assets/images/SpritesheetSW.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
    Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), {100, 100});
    ships.push_back(inv);
}

void Render() {
    for (const auto& s : ships) {
        window.draw(*s);
    }
}

void Update(float dt) {
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
        Update(dt);

        window.clear();
        Render();
        window.display();
    }

    return 0;
}
