#include <SFML/Graphics.hpp>
#include <iostream>
#include <Ship.hpp>
#include <Game.hpp>

std::vector<Ship *> ships;

// Necesitas crear una ventana (sf::RenderWindow) para dibujar en ella.
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

sf::Texture spritesheet;
sf::Sprite invader;

void Load() {
  if (!spritesheet.loadFromFile("assets/images/SpritesheetSW.png")) {
    std::cerr << "Failed to load spritesheet!" << std::endl;
  }
  invader.setTexture(spritesheet);
  invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Render() {
  window.draw(invader);
}

int main() {
  // Llama a la función Load() para cargar tus recursos.
  Load();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Llama a la función Render() para dibujar en la ventana.
    window.clear();
    Render();
    window.display();
  }

  return 0;
}