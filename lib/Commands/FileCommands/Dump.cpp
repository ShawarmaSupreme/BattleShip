#include "Dump.h"

void Dump::run(const CommandArguments& arguments, Field& field) {
    filePath = arguments.stringValue;

    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        result = "not ok";
        return;
    }

    outFile << field.getWidth() << ' ' << field.getHeight() << '\n';

    std::vector<Ship> ships = field.getShips();

    for (Ship ship : ships) {
        std::cout << ship.getSize() << ' ' <<
        (ship.getIsHorizontal() ? 'h' : 'v') << ' ' <<
        ship.getX() << ' ' << ship.getY() << '\n';

        outFile << ship.getSize() << ' ' <<
        (ship.getIsHorizontal() ? 'h' : 'v') << ' ' <<
        ship.getX() << ' ' << ship.getY() << '\n';
    }

    outFile.close();
    result = "ok";
}