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

Ship::Ship() {};

Ship::Ship(sf::IntRect ir) : Sprite() {
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;