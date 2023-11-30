#pragma once
#include <SFML/Graphics.hpp>

class Ventana {
public:
    Ventana(int width, int height, const std::string& title) : window(sf::VideoMode(width, height), title) {}

    void Clear() {
        window.clear();
    }

    void Display() {
        window.display();
    }

    void Close() {
        window.close();
    }

    bool IsOpen() const {
        return window.isOpen();
    }

    sf::RenderWindow& GetRenderWindow() {
        return window;
    }

private:
    sf::RenderWindow window;
};
