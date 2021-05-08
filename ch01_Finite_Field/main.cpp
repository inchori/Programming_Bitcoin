#include <iostream>
#include "ecc.h"

int main() {
    FieldElement fieldElement1;
    FieldElement fieldElement2;
    FieldElement fieldElement3;

    fieldElement1.init(7, 13);
    fieldElement2.init(8, 13);
    fieldElement3.init(10, 13);

    printf("%d\n", fieldElement1.power(-3) == fieldElement2);
    return 0;
}
