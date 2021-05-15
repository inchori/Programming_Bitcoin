/**
 * 2020/05/07 송인철
 * Programming Bitcoin Chapter 01. Finite Field
 * TextBook and Practice code by C++
 */

#ifndef HELLO_ECC_H
#define HELLO_ECC_H

#include <iostream>
#include <cmath>

class FieldElement {
public:
    int num;
    int prime;
public:
    FieldElement(int num, int prime) : num(num), prime(prime) { //constructor
        if (num >= prime || num < 0) {
            std::cout << "Num " << num << " not in field range 0 to " << prime - 1 << std::endl;
        }
    }
    //void init(int num, int prime);
    void repr() const;
    bool operator == (FieldElement &ref);
    bool operator != (FieldElement &ref);
    FieldElement add(FieldElement &ref);
    FieldElement sub(FieldElement &ref);
    FieldElement mul(FieldElement &ref);
    FieldElement power(int exponent);
    FieldElement truediv(FieldElement &ref); //실수 나눗셈
};

#endif //HELLO_ECC_H