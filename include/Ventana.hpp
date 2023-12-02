#pragma once
#include <SFML/Graphics.hpp>

constexpr int ventanaWidth = 800;
constexpr int ventanaHeight = 600;
constexpr int invaders_rows = 5;
constexpr int invaders_columns = 12;

extern sf::Texture spritesheet;

class Ventana {
public:
    Ventana(int width, int height, const char* title);
    ~Ventana();

    void run();

    void Draw(const sf::Drawable& drawable) {
        mWindow.draw(drawable);
    }

    bool IsOpen() const {
        return mWindow.isOpen();
    }

    sf::RenderWindow& GetRenderWindow() {
        return mWindow;
    }

    void Close() {
        mWindow.close();
    }

    void Clear() {
        mWindow.clear();
    }

    void Display() {
        mWindow.display();
    }

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    sf::Sprite mInvaders[invaders_rows][invaders_columns];
    sf::Clock mClock;
};

// Destructor
inline Ventana::~Ventana() {
    // Aquí puedes agregar cualquier lógica de limpieza necesaria
}

// Constructor
inline Ventana::Ventana(int width, int height, const char* title) : mWindow(sf::VideoMode(width, height), title) {
    // Aquí puedes agregar cualquier lógica de inicialización necesaria
}