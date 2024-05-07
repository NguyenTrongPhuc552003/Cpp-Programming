//
// Created by Trong_Phuc on 18/11/2023.
//

#ifndef POINTER_SHAPE_H
#define POINTER_SHAPE_H


class Shape {
private:
    float (*computeArea)(Shape *shape){};

public:
    static float getArea(Shape *shape);
    void setComputeArea(float (*area)(Shape *shape));
};


#endif //POINTER_SHAPE_H
