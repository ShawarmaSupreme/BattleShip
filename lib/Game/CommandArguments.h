#pragma once

#include <string>

class CommandArguments {
    public:
        std::string name = "";
        std::string stringValue = "";
        std::string stringValue2 = "";
        int value1 = 0;
        int value2 = 0;

        bool isValue = true;
    };