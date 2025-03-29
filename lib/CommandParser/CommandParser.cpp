#include "CommandParser.h"

CommandArguments CommandParser::ParseCommand(const std::string& input) {
    CommandArguments com;

    std::istringstream stream(input);
    std::string cmd;

    stream >> cmd;

    if (cmd == "exit") {
        com.name = cmd;
    } else if (cmd == "ping") {
        com.name = cmd;
    } else if (cmd == "create") {
        com.name = cmd;
        stream >> com.stringValue;
    } else if (cmd == "start") {
        com.name = cmd;
    } else if (cmd == "stop") {
        com.name = cmd;
    } else if (cmd == "set") {
        com.name = cmd;
        stream >> com.stringValue;
        if (com.stringValue == "strategy" || com.stringValue == "result") {
            stream >> com.stringValue2;
        } else {
            stream >> com.value1;
            if (com.stringValue == "count") {
                stream >> com.value2;
            }
        }
    } else if (cmd == "get") {
        com.name = cmd;
        stream >> com.stringValue;
        if (com.stringValue == "count") {
            stream >> com.value1;
        }
    } else if (cmd == "shot") {
        com.name = cmd;
        if (stream >> com.value1 >> com.value2) {
        } else {
            com.value1 = com.value2 = -1;
        }
    } else if (cmd == "finished") {
        com.name = cmd;
    } else if (cmd == "win") {
        com.name = cmd;
    } else if (cmd == "lose") {
        com.name = cmd;
    } else if (cmd == "dump") {
        com.name = cmd;
        stream >> com.stringValue;
    } else if (cmd == "load") {
        com.name = cmd;
        stream >> com.stringValue;
    } else if (cmd == "miss" || cmd == "hit" || cmd == "kill") {
        com.name = "shot";
        com.stringValue = cmd;
    } else {
        com.isValue = false;
    }

//    std::cout << com.name << ' ' << com.value1 << ' ' <<
//    com.value2 << ' ' << com.stringValue << ' ' << com.stringValue2 << '\n';

    return com;
}