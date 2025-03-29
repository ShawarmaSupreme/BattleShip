#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include "Ship.h"

class Field {
private:
    struct Config {
        int singleShipCount = 0;
        int doubleShipCount = 0;
        int tripleShipCount = 0;
        int quadrupleShipCount = 0;
        int width = 0;
        int height = 0;
    };
    Config config;
    std::vector<Ship> ships;
public:
    bool isSlave;
    int countOfShips;
    int countOfEnemyKilled = 0;
    int countOfMineKilled = 0;

    bool isCustom = false;

    Field(int width, int height);
    Field();

    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);

    bool isPossibleToPlaceShip(Ship newShip);
    void addShip(const Ship& ship);
    int getSize();

    void setConfig(int single, int duble, int triple, int quatro, int width, int height);
    std::vector<Ship> getShips() const;

    std::string shot(int x, int y);

    void setSingleShipCount(int count);
    void setDoubleShipCount(int count);
    void setTripleShipCount(int count);
    void setQuadroShipCount(int count);

    int getSingleShipCount() const;
    int getDoubleShipCount() const;
    int getTripleShipCount() const;
    int getQuadroShipCount() const;
};