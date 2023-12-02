#include <Juego.hpp>
sf::Texture spritesheet;
int main() {
    Juego juego(800, 600, "SFML Window");
    juego.Run();

    return 0;
}
//corre Juego.hpp