#pragma once

#include <string>
#include <iostream>

#include "../Game/CommandArguments.h"
#include "../Game/Field.h"

class AbstractCommand {
public:
    virtual void run(const CommandArguments& arguments, Field& field) = 0;

    virtual void printResult(std::ostream& out) const = 0;
};