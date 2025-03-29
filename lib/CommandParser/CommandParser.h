#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "../Game/CommandArguments.h"

class CommandParser {
public:
    CommandArguments ParseCommand(const std::string& input);
};