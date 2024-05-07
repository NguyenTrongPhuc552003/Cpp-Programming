//
// Created by Trong_Phuc on 18/11/2023.
//

#ifndef POINTER_RECTANGLE_H
#define POINTER_RECTANGLE_H


#include "Shape.h"

class Rectangle {
private:
    Shape shape;
    float width{}, height{};

public:
    static float getArea(const Shape *shapeObject);
    static void newRectangle(Rectangle *rectangle);
    static void newLength(Rectangle *rectangle, float width, float height);
};


#endif //POINTER_RECTANGLE_H
