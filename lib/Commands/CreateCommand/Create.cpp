#include "Create.h"

void Create::ShipPlace(int type, int shipTypeCount, Field& field) {
    for (int i = 0; i < shipTypeCount; ++i) {
        bool isPlaced = false;
        Ship newShip(type, 0, 0, false);

        for (int j = 0; j < 3; ++j) {
            std::cout << j;
            newShip.setX(getRandomX());
            newShip.setY(getRandomY());

            if (field.isPossibleToPlaceShip(newShip)) {
                isPlaced = true;
                field.addShip(newShip);
                break;
            }

            newShip.setHorisontal(true);

            if (field.isPossibleToPlaceShip(newShip)) {
                isPlaced = true;
                field.addShip(newShip);
                break;
            }
        }

        if (!isPlaced) {
            for (int x = 1; x < field.getWidth() + 1 && !isPlaced; ++x) {
                for (int y = 1; y < field.getHeight() + 1 && !isPlaced; ++y) {
                    newShip.setX(x);
                    newShip.setY(y);
                    if (field.isPossibleToPlaceShip(newShip)) {
                        isPlaced = true;
                        field.addShip(newShip);
                    }
                    newShip.setHorisontal(false);
                    if (field.isPossibleToPlaceShip(newShip)) {
                        isPlaced = true;
                        field.addShip(newShip);
                    }
                }
            }
        }
    }
}

void Create::run(const CommandArguments& arguments, Field& field) {
    field.setConfig(config.singleShipCount, config.doubleShipCount, config.tripleShipCount, config.quadrupleShipCount, config.width, config.height);
    if (arguments.stringValue == "master") {
        ShipPlace(4, config.quadrupleShipCount, field);
        ShipPlace(3, config.tripleShipCount, field);
        ShipPlace(2, config.doubleShipCount, field);
        ShipPlace(1, config.singleShipCount, field);
        field.isSlave = false;
    } else {
        field.isSlave = true;
    }
}