#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main() {
    bool active = 1;
    while (active) {
        Game game;
        active = game.run();
    }
    return 0;
}