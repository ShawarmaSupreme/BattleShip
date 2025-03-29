#pragma once

#include <vector>
#include <iostream>

class Ship {
private:
    int size;
    int x;
    int y;
    bool isHorizontal;
    int countOfHit;
public:
    Ship(int size, int x, int y, bool isHorizontal) : 
        size(size), x(x), y(y), isHorizontal(isHorizontal) {countOfHit = 0;}
    Ship(int size, int x, int y) : size(size), x(x), y(y) {countOfHit = 0;}

    int getSize() const {
        return size;
    }

    int getX() const { 
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }

    bool getIsHorizontal() const {
        return isHorizontal;
    }

    void setHorisontal(bool set) {
        this->isHorizontal = set;
    }

    bool isAllHit() {
        if (countOfHit >= size) return true;
        else return false;
    }

    bool isHited(int xShot, int yShot) {
        if (isHorizontal && y == yShot) {
            for (int i = 0; i < size; ++i) {
                if (x + i == xShot) {
                    countOfHit++;
                    return true;
                }
            }
        } else if (!isHorizontal && x == xShot) {
            for (int i = 0; i < size; ++i) {
                if (y + i == yShot) {
                    countOfHit++;
                    return true;
                }
            }
        }
        return false;
    }
};