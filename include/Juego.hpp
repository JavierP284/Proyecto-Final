#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Ventana.hpp>
#include <Invader.hpp>
#include <Bala.hpp>
#include <Jugador.hpp>
std::vector<Bala*> balas;
class Juego {
public:
    Juego(int ventanaWidth, int ventanaHeight, const char* title);
    ~Juego();

    void Run();

private:
    void Load();
    void Render();
    void Update(float dt);
    void HandleEvents();
    void InitializeBalas();

private:
    Ventana ventana;
    sf::Texture spritesheet;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<Nave*> naves;
    std::vector<Bala*> balas;
};

Juego::Juego(int ventanaWidth, int ventanaHeight, const char* title)
    : ventana(ventanaWidth, ventanaHeight, title) {}

Juego::~Juego() {
    for (auto& nave : naves) {
        delete nave;
    }

    for (auto& bala : balas) {
        delete bala;
    }
}

void Juego::Run() {
    Load();

    sf::Clock clock;

    while (ventana.IsOpen()) {
        HandleEvents();

        float dt = clock.restart().asSeconds();

        Update(dt);

        ventana.Clear();
        Render();
        ventana.Display();
    }
}

void Juego::Load() {
    if (!backgroundTexture.loadFromFile("assets/images/background.jpg")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    if (!spritesheet.loadFromFile("assets/images/SpritesheetSW2.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

    for (int r = 0; r < invaders_rows; ++r) {
        sf::IntRect rect(0, 0, 38, 40);
        for (int c = 0; c < invaders_columns; ++c) {
            sf::Vector2f position(100.0f + c * 40.0f, 100.0f + r * 40.0f);
            Invader* inv = new Invader(rect, position);
            inv->setTexture(spritesheet);
            naves.push_back(inv);
        }
    }

    Jugador* jugador = new Jugador();
    jugador->setTexture(spritesheet);
    naves.push_back(jugador);

    // Inicializa el vector de balas
    InitializeBalas();
}

void Juego::Render() {
    ventana.Draw(backgroundSprite);

    for (const auto& s : naves) {
        ventana.Draw(*s);
    }

    for (const auto& bala : balas) {
        ventana.Draw(*bala);
    }
}

void Juego::Update(float dt) {
    for (auto it = naves.begin(); it != naves.end(); ) {
        (*it)->Pilotar(dt);

        Bala* bala = dynamic_cast<Bala*>(*it);
        if (bala && bala->ShouldBeDestroyed()) {
            delete *it;
            it = naves.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = balas.begin(); it != balas.end(); ) {
        (*it)->Desaparecer(dt);

        if ((*it)->ShouldBeDestroyed()) {
            delete *it;
            it = balas.erase(it);
        } else {
            ++it;
        }
    }
}

void Juego::HandleEvents() {
    sf::Event event;
    while (ventana.GetRenderWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            ventana.Close();
        }
    }
}

void Juego::InitializeBalas() {
    balas.clear();
}