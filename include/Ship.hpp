#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp" // Assuming Game.hpp contains necessary declarations
#include "Bullet.hpp" // Assuming you have a Bullet class

class Ship : public sf::Sprite
{
protected:
    sf::IntRect _sprite;

public:
    Ship(sf::IntRect ir) : sf::Sprite(), _sprite(ir)
    {
        setTexture(spritesheet);
        setTextureRect(_sprite);
    }

    virtual ~Ship() = default;

    virtual void Update(const float &dt) {}
};

class Player : public Ship {
private:
    static std::vector<Bullet*> bullets;

public:
    Player() : Ship(sf::IntRect(135, 0, 40, 32))
    {
        setPosition({gameHeight * 0.5f, gameHeight - 32.f});
    }

    void Update(const float &dt) override {
        Ship::Update(dt);

        // Fire bullet
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.push_back(new Bullet(getPosition(), false));
        }

        // Update bullets
        for (auto& bullet : bullets) {
            bullet->Update(dt);
        }

        // Remove bullets that are off-screen or have hit something (add your logic)
        bullets.erase(
            std::remove_if(
                bullets.begin(),
                bullets.end(),
                [](Bullet* bullet) {
                    // Add your condition for removing bullets, e.g., off-screen check
                    return bullet->getPosition().y < 0; // Remove when bullet goes off the top of the screen
                }
            ),
            bullets.end()
        );
    }

    static std::vector<Bullet*>& GetBullets() {
        return bullets;
    }
};

// Initialize the static vector
std::vector<Bullet*> Player::bullets;
