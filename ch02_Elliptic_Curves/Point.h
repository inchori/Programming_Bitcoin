/**
 * 2020/05/08 송인철
 * Programming Bitcoin Chapter 02. Elliptic Curves
 * TextBook and Practice code by C++
 */

#ifndef HELLO_POINT_H
#define HELLO_POINT_H

#include <iostream>

class Point {
private:
    int x, y, a, b;

public:
    Point(int x, int y, int a, int b) : x(x), y(y), a(a), b(b) {
        if (this->x == 0 && this->y == 0) return;

        if (pow(this->y, 2) != pow(this->x, 3) + a * x + b) {
            std::cout << "(" << x << ", " << y << ") is not on the curve" << std::endl;
        }
    }
    //void init(int x, int y, int a, int b);
    bool operator == (Point &ref);
    bool operator != (Point &ref);
    Point add(Point &ref);
};

#endif //HELLO_POINT_H