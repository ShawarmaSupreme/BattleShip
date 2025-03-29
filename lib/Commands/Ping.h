#pragma once

#include "AbstractCommand.h"

class Ping : public AbstractCommand {
private:
    std::string result;
public:
    void run(const CommandArguments& arguments, Field& field) override {
        result = "pong";
    }

    void printResult(std::ostream& out) const override {
        out << result << std::endl;
    }
};