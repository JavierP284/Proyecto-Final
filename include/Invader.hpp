#pragma once
#include <SFML/Graphics.hpp>
#include <Ship.hpp>
#include <Game.hpp>

std::vector<Ship*> ships;
class Invader : public Ship {
public:
    // Static properties
    static bool direction;
    static float speed;

    Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
        setOrigin(16, 16);
        setPosition(pos);
    }

    Invader() : Ship() {}

    void Update(const float &dt) override {
        Ship::Update(dt);
        move(dt * (direction ? 1.0f : -1.0f) * speed, 0);
        if ((direction && getPosition().x > gameWidth - 16) ||
            (!direction && getPosition().x < 16)) {
            direction = !direction;
            for (int i = 0; i < Ship.size(); ++i) {
                ships[i]->move(0, 24);
            }
        }
    }
};

// Define static properties
bool Invader::direction = true;  // Set the initial value to true
float Invader::speed = 5.0f;     // Set the initial value to 5.0f
