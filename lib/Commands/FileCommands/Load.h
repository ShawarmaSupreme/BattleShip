#pragma once

#include "fstream"

#include "../../Game/Ship.h"
#include "../AbstractCommand.h"

class Load : public AbstractCommand {
    private:
    std::string filePath;
    std::string result;

    public:
    Load() = default;

    void run(const CommandArguments& arguments, Field& field) override;

    void printResult(std::ostream& out) const override {
        out << result << '\n';
    };
};