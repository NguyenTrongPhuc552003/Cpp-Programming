//
// Created by Trong_Phuc on 22/02/2023.
//

#ifndef OOP_V3_MYMATH_H
#define OOP_V3_MYMATH_H

using namespace std;

template <class diversified>
void swapData(diversified& x, diversified& y) {
    diversified temp = x;
    x = y;
    y = temp;
}

class Calculation {
private:
    float a, b, c, d;
public:
    void setValues(int& x, int& y, int& z, int& t) {
        a = float(x);
        b = float(y);
        c = float(z);
        d = float(t);
    }
    float getResult();
};

float Calculation::getResult() {
    return (a / b) + (c / d);
}

#endif //OOP_V3_MYMATH_H
