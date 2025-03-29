#include "Game.h"

#include <iostream>

void Game::startGame() {
    isRunning = true;

    manager.makeMap();

    while (isRunning) {
        std::string input;
        std::getline(std::cin, input);

        Game::arguments = parser.ParseCommand(input);

        if (arguments.isValue && arguments.name != "exit") {
            manager.runCommand(arguments, field);
        } else if (!arguments.isValue) {
            std::cout << "repeat\n";
        } else {
            std::cout << "ok\n";
            isRunning = false;
        }
    }
}