#pragma once

#include "AbstractCommand.h"

class Finished : public AbstractCommand {
private:
    std::string result;
public:
    void run(const CommandArguments& arguments, Field& field) override {
        if (field.countOfEnemyKilled == field.countOfShips ||
                field.countOfMineKilled == field.countOfShips) {
            result = "yes";
        } else {
            result = "no";
        }
    }

    void printResult(std::ostream& out) const {
        out << result << '\n';
    }
};