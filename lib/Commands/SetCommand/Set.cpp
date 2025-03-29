#include "Set.h"

#include "../CreateCommand/Create.h"

void Set::widthSet(int width, Field& field) const {
    field.setWidth(width);
}

void Set::heightSet(int height, Field& field) const {
    field.setHeight(height);
}

void Set::run(const CommandArguments& arguments, Field& field) {
    if (arguments.stringValue == "width") {
        widthSet(arguments.value1, field);
    } else if (arguments.stringValue == "height") {
        heightSet(arguments.value1, field);
    } else if (arguments.stringValue == "count") {
        if (arguments.value1 == 1) {
            field.setSingleShipCount(arguments.value2);
        } else if (arguments.value1 == 2) {
            field.setDoubleShipCount(arguments.value2);
        } else if (arguments.value1 == 3) {
            field.setTripleShipCount(arguments.value2);
        } else if (arguments.value1 == 4) {
            field.setQuadroShipCount(arguments.value2);
        }
    } else if (arguments.stringValue == "strategy") {
        if (arguments.stringValue2 == "ordered") {
            field.isCustom = false;
        } else {
            field.isCustom = true;
        }
    }
}