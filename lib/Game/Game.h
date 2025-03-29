#pragma once

#include "../CommandManager/CommandManager.h"
#include "../CommandParser/CommandParser.h"
#include "Field.h"

class Game {
private:
    bool isRunning;
public:
    Game() = default;
    Field field;
    CommandParser parser;
    CommandArguments arguments;
    CommandManager manager;
    void startGame();
};