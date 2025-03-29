#pragma once

#include "../AbstractCommand.h"
#include "../CreateCommand/Create.h"

class Shot : public AbstractCommand {
private:
    int currentX = 1;
    int currentY = 1;
    std::string result;
    bool isHit = false;
    int length = 1;
    int side = 0;
    int nX, nY;
public:
    void run(const CommandArguments& arguments, Field& field) override;

    void miss(Field& field);

    void kill(Field& field);

    void hit(Field& field);

    void printResult(std::ostream& out) const override {
        out << result << '\n';
    };

    void trickyShot(Field& field);

    void orderedShot(Field& field);
};
