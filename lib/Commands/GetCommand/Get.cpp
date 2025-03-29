#include "Get.h"

void Get::run(const CommandArguments& arguments, Field& field) {
    if (arguments.stringValue == "width") {
        result = field.getWidth();
    } else if (arguments.stringValue == "height") {
        result = field.getHeight();
    } else if (arguments.stringValue == "count") {
        if (arguments.value1 == 1) {
            result = field.getSingleShipCount();
        } else if (arguments.value1 == 2) {
            result = field.getDoubleShipCount();
        } else if (arguments.value1 == 3) {
            result = field.getTripleShipCount();
        } else if (arguments.value1 == 4) {
            result = field.getQuadroShipCount();
        }
    }
}