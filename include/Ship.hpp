#pragma once
#include <SFML/Graphics.hpp>
#include <Game.hpp>

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    //Default constructor is hidden
    Ship();
public:
    //Constructor that takes a sprite
    explicit Ship(sf::IntRect ir);
    //Pure virtual deconstructor -- makes this an abstract class
    virtual ~Ship() = 0;
    //Update, virtual so can be overrided, but not pure virtual
    virtual void Update(const float &dt);
};
class Invader : public Ship {
public:
    static bool direction;
    static float speed;
    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float &dt) override;
};

Ship::Ship() {};
    bool Invader::direction;
    float Invader::speed;
Ship::Ship(sf::IntRect ir) : Sprite() {
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;

Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
    setOrigin(16, 16);
    setPosition(pos);
}

void Invader::Update(const float &dt) {
    Ship::Update(dt);
}