#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "../Commands/Ping.h"
#include "../Commands/Finished.h"
#include "../Commands/Lose.h"
#include "../Commands/Win.h"
#include "../Commands/CreateCommand/Create.h"
#include "../Commands/SetCommand/Set.h"
#include "../Commands/GetCommand/Get.h"
#include "../Commands/ShotCommand/Shot.h"
#include "../Commands/FileCommands/Dump.h"
#include "../Commands/FileCommands/Load.h"

class CommandManager {
private:

std::unordered_map<std::string, AbstractCommand*> hashTable;

public:
    CommandManager() = default;

    void makeMap();

    void runCommand(const CommandArguments& arguments, Field& field);

    class Create* getCreateCommand() {
        return (Create*) hashTable["create"];
    };
};