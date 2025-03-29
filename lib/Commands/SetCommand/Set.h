#pragma once

#include "../../Game/CommandArguments.h"
#include "../AbstractCommand.h"

class Set : public AbstractCommand {
public:
    void run(const CommandArguments& arguments, Field& field) override;

    void widthSet(int width, Field& field) const;

    void heightSet(int height, Field& field) const;

    void shipSet(int size, int count) const;

    void resultSet(std::string result) const;

    void printResult(std::ostream& out) const override {
        out << "ok\n";
    }

};