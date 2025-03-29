#include "Field.h"
#include <cmath>

Field::Field(int width, int height) {
    config.width = width;
    config.height = height;
}

Field::Field() = default;

int Field::getWidth() const {
    return this->config.width;
}

void Field::setWidth(int width) {
    this->config.width = width;
}

int Field::getHeight() const {
    return this->config.height;
}

void Field::setHeight(int height) {
    this->config.height = height;
}

/*bool Field::isPossibleToPlaceShip(Ship newShip) {
    int newShipXEnd = newShip.getX() + (newShip.getIsHorizontal() ? newShip.getSize() - 1 : 0);
    int newShipYEnd = newShip.getY() + (!newShip.getIsHorizontal() ? newShip.getSize() - 1 : 0);

    if (newShipXEnd > config.width || newShipYEnd > config.height)
        return false;

    for (Ship ship : ships) {
        if (ship.getIsHorizontal() && newShip.getIsHorizontal()) {
            if (abs(ship.getY() - newShip.getY()) < 2 &&
            (ship.getX() > newShip.getX() ?
            (ship.getX() - newShip.getX() - newShip.getSize() + 1 < 2) :
             (newShip.getX() - ship.getX() - ship.getSize() + 1 < 2)))
                return false;
        } else if (ship.getIsHorizontal() && !newShip.getIsHorizontal()) {
            if (ship.getX() > newShip.getX()) {
                if (ship.getX() - newShip.getX() < 2 && (ship.getY() > newShip.getY() ?
                (ship.getY() - newShip.getY() < 2) :
                (newShip.getY() + newShip.getSize() >= ship.getSize()))) {
                    return false;
                }
            } else if (ship.getX() + ship.getSize() - 1  - newShip.getX() < 2
                && (ship.getY() > newShip.getY()
                    ? (ship.getY() - newShip.getY() < 2)
                    : (newShip.getY() + newShip.getSize() >= ship.getSize())
                )
            ) {
                return false;
            }
        } else if (!ship.getIsHorizontal() && newShip.getIsHorizontal()) {
            if (newShip.getX() > ship.getX()) {
                if (newShip.getX() - ship.getX() < 2 && (newShip.getY() > ship.getY() ?
                (newShip.getY() - ship.getY() < 2) :
                (ship.getY() + ship.getSize() >= newShip.getSize()))) {
                    return false;
                }
            } else if (newShip.getX() + newShip.getSize() - 1  - ship.getX() < 2
                       && (newShip.getY() > ship.getY()
                           ? (newShip.getY() - ship.getY() < 2)
                           : (ship.getY() + ship.getSize() >= newShip.getSize())
                       )
                    ) {
                return false;
            }
        } else if (!ship.getIsHorizontal() && !newShip.getIsHorizontal()) {
            if (abs(ship.getX() - newShip.getX()) < 2 &&
                (ship.getY() > newShip.getY() ?
                 (ship.getY() - newShip.getY() - newShip.getSize() + 1 < 2) :
                 (newShip.getY() - ship.getY() - ship.getSize() + 1 < 2)))
                return false;
        }
    }
    return true;
}*/

bool Field::isPossibleToPlaceShip(Ship newShip) {
    for (Ship& ship : ships) {
        for (int i = 0; i < ship.getSize(); ++i) {
            for (int j = 0; j < newShip.getSize(); ++j) {
                int x = ship.getX();
                int y = ship.getY();
                int nx = newShip.getX();
                int ny = newShip.getY();

                if (ship.getIsHorizontal()) x += i;
                else y += i;
                if (newShip.getIsHorizontal()) nx += j;
                else ny += j;

                if (abs(x - nx) < 2 && abs(y - ny) < 2) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Field::addShip(const Ship& ship) {
    ships.push_back(ship);
    if (ship.getSize() == 1) this->config.singleShipCount++;
    if (ship.getSize() == 2) this->config.doubleShipCount++;
    if (ship.getSize() == 3) this->config.tripleShipCount++;
    if (ship.getSize() == 4) this->config.quadrupleShipCount++;
}

int Field::getSize() {
    return config.singleShipCount + config.doubleShipCount + config.tripleShipCount + config.quadrupleShipCount;
}

void Field::setConfig(int single, int duble, int triple, int quatro, int width, int height) {
    config.singleShipCount = single;
    config.doubleShipCount = duble;
    config.tripleShipCount = triple;
    config.quadrupleShipCount = quatro;
    config.width = width;
    config.height = height;
}

std::vector<Ship> Field::getShips() const {
    return this->ships;
}

std::string Field::shot(int x, int y) {
    for (Ship& ship : ships) {
//        std::cout << ship.getSize() << ' ' <<
//                  (ship.getIsHorizontal() ? 'h' : 'v') << ' ' <<
//                  ship.getX() << ' ' << ship.getY() << '\n';

        if (ship.isHited(x, y)) {
            if (ship.isAllHit()) {
                countOfEnemyKilled++;
                return "kill";
            } else {
                return "hit";
            }
        }
    }
    return "miss";
}

void Field::setSingleShipCount(int count) {
    config.singleShipCount = count;
}

void Field::setDoubleShipCount(int count) {
    config.doubleShipCount = count;
}

void Field::setTripleShipCount(int count) {
    config.tripleShipCount = count;
}

void Field::setQuadroShipCount(int count) {
    config.quadrupleShipCount = count;
}

int Field::getSingleShipCount() const {
    return config.singleShipCount;
}

int Field::getDoubleShipCount() const {
    return config.doubleShipCount;
}

int Field::getTripleShipCount() const {
    return config.tripleShipCount;
}

int Field::getQuadroShipCount() const {
    return config.quadrupleShipCount;
}