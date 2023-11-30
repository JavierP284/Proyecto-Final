#pragma once
#include <SFML/Graphics.hpp>
#include <Nave.hpp>
#include <Game.hpp>

std::vector<Nave *> naves;
class Invader : public Nave
{
public:
    // Define static properties
    static bool direction; // Set the initial value to true
    static float speed;    // Set the initial value to 5.0f

    Invader(sf::IntRect ir, sf::Vector2f pos) : Nave(ir)
    {
        setOrigin(16, 16);
        setPosition(pos);
    }

    Invader() : Nave() {}

    void Update(const float &dt) override
    {
        Nave::Update(dt); // Lamando al metodo de la clase base
        move(dt * (direction ? 5.0f : -5.0f) * speed, 0);
        if ((direction && getPosition().x > gameWidth - 16) ||
            (!direction && getPosition().x < 16))
        {
            direction = !direction;
            for (int i = 0; i < naves.size(); ++i)
            {
                naves[i]->move(0, 24);
            }
        }
    }
};