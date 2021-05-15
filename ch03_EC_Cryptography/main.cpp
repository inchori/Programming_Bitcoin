#include "ecc.h"
#include "Point.h"

int main() {
    int prime = 223;

    FieldElement A(0, prime);
    FieldElement B(7, prime);

    FieldElement X1(192, prime);
    FieldElement Y1(105, prime);

    FieldElement X2(17, prime);
    FieldElement Y2(56, prime);

    int a = A.num;
    int b = B.num;

    int x1 = X1.num;
    int y1 = Y1.num;

    int x2 = X2.num;
    int y2 = Y2.num;

    Point P1(x1, y1, a, b, prime);
    Point P2(x2, y2, a, b, prime);

    P1.add(P2);

    return 0;
}