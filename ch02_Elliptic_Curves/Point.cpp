/**
 * 2020/05/08 송인철
 * Programming Bitcoin Chapter 02. Elliptic Curves
 * TextBook and Practice code by C++
 */

#include "Point.h"
#include <cmath>

void Point::init(int x, int y, int a, int b) {
    this->a = a;
    this->b = b;
    this->x = x;
    this->y = y;

    if (this->x == 0 && this->y == 0) return;

    if (pow(this->y, 2) != pow(this->x, 3) + a * x + b) {
        std::cout << "(" << x << ", " << y << ") is not on the curve" << std::endl;
    }
}

bool Point::operator == (Point &ref) {
    return (this->x == ref.x) && (this->y == ref.y) && (this->a == ref.a) && (this->b == ref.b);
}

bool Point::operator != (Point &ref) {
    return (this->x != ref.x) || (this->y != ref.y) || (this->a != ref.a) || (this->b != ref.b);
}

Point Point::add(Point &ref) {
    if (this->a != ref.a || this->b != ref.b) {
        std::cout << "Points " << this << ", " << &ref << " are not on the same curve" << std::endl;
    }
    if (this->x == 1e9) return ref;
    if (ref.x == 1e9) return *this; //항등원

    if (this->x != ref.x) { //x1 != x2 덧셈, Practice 2.5
        int s = (abs(ref.y - this->y)) / (abs(ref.x - this->x));
        int x3 = pow(s, 2) - this->x - ref.x;
        int y3 = s * (this->x - x3) - this->y;

        Point result;
        result.init(x3, y3, this->a, this->b);
        return result;
    }

    if (this->x == ref.x) { //x1 == x2 덧셈, Practice 2.7
        int s = (3 * pow(this->x , 2) + this->a) / 2 * this->y;
        int x3 = pow(s, 2) - 2 * this->x;
        int y3 = s * (this->x - x3) - this->y;

        Point result;
        result.init(x3, y3, this->a, this->b);
        return result;
    }

    if (*this == ref && this->y == 0 * this->x) { // Exception Handling
        Point result;
        result.init(0, 0, this->a, this->b);

    }
}


