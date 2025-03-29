#include "Shot.h"

void Shot::trickyShot(Field& field) {
    static int diagonal = 0;
    static bool primaryDiagonal = true;

    int width = field.getWidth();
    int height = field.getHeight();

    while (diagonal < width + height - 1) {
        if (primaryDiagonal) {
            for (int x = 0; x < width; ++x) {
                int y = diagonal - x;
                if (y >= 0 && y < height) {
                    currentX = x;
                    currentY = y;
                    result = std::to_string(currentX) + ' ' + std::to_string(currentY);
                    return;
                }
            }
        }
        else {
            for (int x = 0; x < width; ++x) {
                int y = x - diagonal;
                if (y >= 0 && y < height) {
                    currentX = x;
                    currentY = y;
                    result = std::to_string(currentX) + ' ' + std::to_string(currentY);
                    return;
                }
            }
        }
        if (primaryDiagonal) {
            primaryDiagonal = false;
        } else {
            primaryDiagonal = true;
            ++diagonal;
        }
    }
    result = "finish";
}

void Shot::orderedShot(Field& field) {
    result = std::to_string(currentX) + ' ' + std::to_string(currentY);
}

void Shot::miss(Field& field) {
    if (isHit) {
        if (length == 2) {
            side++;
        } else {
            side = (side + 2) % 4;
            length = 1;
        }
    } else {
        ++currentX;
        if (currentX >= field.getWidth()) {
            currentX = 1;
            ++currentY;
        }
    }
    result = "ok";
}

void Shot::kill(Field& field) {
    field.countOfEnemyKilled++;
    isHit = true;
    ++currentX;
    if (currentX == field.getWidth()) {
        currentX = 1;
        ++currentY;
    }
    result = "ok";
}

void Shot::hit(Field& field) {
    isHit = true;
    nX = currentX;
    nY = currentY;
    if (side == 0) nX += length;
    else if (side == 1) nY -= length;
    else if (side == 2) nX -= length;
    else if (side == 3) nY += length;
    length++;
    result = std::to_string(nX) + ' ' + std::to_string(nY);
}

void Shot::run(const CommandArguments& arguments, Field& field) {
    if (arguments.stringValue == "miss") {
        miss(field);
    } else if (arguments.stringValue == "kill") {
        kill(field);
    } else if (arguments.stringValue == "hit") {
        hit(field);
    } else if (arguments.value1 == -1) {
        if (field.isCustom) {
            trickyShot(field);
        } else {
            orderedShot(field);
        }
    } else {
        result = field.shot(arguments.value1, arguments.value2);
    }
}