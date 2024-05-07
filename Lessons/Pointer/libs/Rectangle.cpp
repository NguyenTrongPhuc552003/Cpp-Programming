//
// Created by Trong_Phuc on 18/11/2023.
//

#include "Rectangle.h"

float Rectangle::getArea(const Shape *shapeObject) {
    const auto *rectangle = (const Rectangle *) shapeObject;
    return rectangle->width * rectangle->height;
}

void Rectangle::newRectangle(Rectangle *rectangle) {
    rectangle->width = rectangle->height = 0.f;
    rectangle->shape.setComputeArea(reinterpret_cast<float (*)(Shape *)>(Rectangle::getArea));
}

void Rectangle::newLength(Rectangle *rectangle, float width, float height) {
    Rectangle::newRectangle(rectangle);
    rectangle->width = width;
    rectangle->height = height;
}
