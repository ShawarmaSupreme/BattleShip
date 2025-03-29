#include "Load.h"

void Load::run(const CommandArguments& arguments, Field& field) {
    filePath = arguments.stringValue;

    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        result = "not ok";
        return;
    }

    int width, height;
    inFile >> width >> height;

    std::cout << width << ' ' << height << '\n';

    field.setWidth(width);
    field.setHeight(height);

    int size, x, y;
    char vh;

    while (inFile >> size >> vh >> x >> y) {
        field.addShip((Ship(size, x, y, vh == 'h')));
    }

    inFile.close();
    result = "ok";
}