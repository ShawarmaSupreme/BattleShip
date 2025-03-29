#pragma once

#include "../AbstractCommand.h"
#include <random>

class Create : public AbstractCommand {
    private:
    struct Config {
        int singleShipCount = 4;
        int doubleShipCount = 3;
        int tripleShipCount = 2;
        int quadrupleShipCount = 1;
        int width = 10;
        int height = 10;
    };

    Config config;

    std::string result;

    std::mt19937 rng;
    std::uniform_int_distribution<int> distX;
    std::uniform_int_distribution<int> distY;

    public:
    Create() : rng(std::random_device{}()), distX(1, config.width), distY(1, config.height) {};

    void run(const CommandArguments& arguments, Field& field) override;

    int getRandomX() {
        return distX(rng);
    }

    int getRandomY() {
        return distY(rng);
    }

    void ShipPlace(int type, int shipTypeCount, Field& field);

    void printResult(std::ostream& out) const override {
        out << "ok\n";
    };
};