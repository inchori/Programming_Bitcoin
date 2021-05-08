#include <iostream>
#include "Point.h"

int main() {
    Point p1;
    Point p2;

    p1.init(-1, -1, 5, 7);
    p2.init(-1, -1, 5, 7);

    Point inf;
    inf.init(1e9, 1e9, 5, 7);
    Point result = p1.add(inf);

    Point result2 = p1.add(p2);
    return 0;
}