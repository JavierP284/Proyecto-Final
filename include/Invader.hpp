// Invader.hpp (combinado con Invader.cpp)
#pragma once
#include <SFML/Graphics.hpp>
#include <Nave.hpp>
#include <Bala.hpp>

class Invader : public Nave {
public:
    static bool direction;
    static float speed;

    Invader(sf::IntRect ir, sf::Vector2f pos);
    void Pilotar(const float &dt) override;

private:
    static std::vector<Nave*>* naves;
};

bool Invader::direction = true;
float Invader::speed = 5.0f;
std::vector<Nave*>* Invader::naves = nullptr;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Nave(ir) {
    setOrigin(16, 16);
    setPosition(pos);
}

void Invader::Pilotar(const float &dt) {
    Nave::Pilotar(dt); // Llamada al método de la clase base
    move(dt * (direction ? 5.0f : -5.0f) * speed, 0);

    if ((direction && getPosition().x > ventanaWidth - 16) || (!direction && getPosition().x < 16)) {
        direction = !direction;
        // Accede a naves usando Invader::naves
        for (int i = 0; Invader::naves && i < Invader::naves->size(); ++i) {
            (*Invader::naves)[i]->move(0, 24);
        }
    }
}