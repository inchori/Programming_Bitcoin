/**
 * 2020/05/08 송인철
 * Programming Bitcoin Chapter 02. Elliptic Curves
 * TextBook and Practice code by C++
 */

#ifndef HELLO_POINT_H
#define HELLO_POINT_H

#include <iostream>
#include "ecc.h"

class Point {
public:
    int x, y, a, b;
    int prime;

public:
    Point(int x, int y, int a, int b, int prime) : x(x), y(y), a(a), b(b), prime(prime) {
        if (this->x == 0 && this->y == 0) return;

        int y2 = pow(this->y, 2);
        int x3 = pow(this->x , 3);
        if (y2 % prime != (x3 + a * x + b) % prime) {
            std::cout << "(" << x << ", " << y << ") is not on the curve" << std::endl;
        }

        else {
            std::cout << "Point(" << x << "," << y << ")_" << a << "_" << b << std::endl;
        }
    }

    //Point init(FieldElement &x, FieldElement &y, FieldElement &a, FieldElement &b);
    //void init(int x, int y, int a, int b);
    bool operator == (Point &ref);
    bool operator != (Point &ref);
    Point add(Point &ref);
};

#endif //HELLO_POINT_H