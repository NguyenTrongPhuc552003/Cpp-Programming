//
// Created by Trong_Phuc on 18/11/2023.
//

#include "Shape.h"

float Shape::getArea(Shape *shape) {
    return shape->computeArea(shape);
}

void Shape::setComputeArea(float (*area)(Shape *)) {
    Shape::computeArea = area;
}
