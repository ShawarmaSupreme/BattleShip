#pragma once

#include "../../Game/CommandArguments.h"
#include "../AbstractCommand.h"

class Get : public AbstractCommand {
private:
    int result;
public:
    void run(const CommandArguments& arguments, Field& field) override;

    void printResult(std::ostream& out) const override {
        out << result << '\n';
    }
};
