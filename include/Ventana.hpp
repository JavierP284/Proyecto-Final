#pragma once
#include <SFML/Graphics.hpp>

class Ventana {
public:
    Ventana(int width, int height, const std::string& title);

    void Clear();
    void Display();
    bool IsOpen() const;
    void Close();

    sf::RenderWindow& GetRenderWindow();

    template <typename T>
    void Draw(const T& drawable) {
        ventana.draw(drawable);
    }

private:
    sf::RenderWindow ventana;
};

Ventana::Ventana(int width, int height, const std::string& title)
    : ventana(sf::VideoMode(width, height), title) {}

void Ventana::Clear() {
    ventana.clear();
}

void Ventana::Display() {
    ventana.display();
}

bool Ventana::IsOpen() const {
    return ventana.isOpen();
}

void Ventana::Close() {
    ventana.close();
}

sf::RenderWindow& Ventana::GetRenderWindow() {
    return ventana;
}