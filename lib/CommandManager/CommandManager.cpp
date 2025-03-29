#include "CommandManager.h"
#include "../Commands/Finished.h"

void CommandManager::makeMap() {
        hashTable["ping"] = new Ping();
        hashTable["create"] = new Create();
        hashTable["set"] = new Set();
        hashTable["get"] = new Get();
        hashTable["shot"] = new Shot();
        hashTable["dump"] = new Dump();
        hashTable["load"] = new Load();
        hashTable["finished"] = new Finished();
        hashTable["lose"] = new Lose();
        hashTable["win"] = new Win();
}

void CommandManager::runCommand(const CommandArguments& arguments, Field& field) {
        if (hashTable.find(arguments.name) != hashTable.end()) {
            hashTable[arguments.name]->run(arguments, field);
            hashTable[arguments.name]->printResult(std::cout);
        } else {
            std::cout << ":(";
        }
}