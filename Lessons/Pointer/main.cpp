#include <iostream>

#include "libs/Rectangle.h"

using namespace std;

int main() {
    Rectangle rectangle;

    Rectangle::newLength(&rectangle, 10.f, 20.f);
    cout << "Rectangle area: " << Shape::getArea(reinterpret_cast<Shape *>(&rectangle)) << endl;
    return 0;
}
