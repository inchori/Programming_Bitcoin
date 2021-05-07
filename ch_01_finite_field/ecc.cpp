/**
 * 2020/05/07 송인철
 * Programming Bitcoin Chapter 01. Finite Field
 * TextBook and Practice code by C++
 */

#include "ecc.h"

void FieldElement::init(int num, int prime) {
    if (num >= prime || num < 0) {
        std::cout << "Num " << num << " not in field range 0 to " << prime - 1 << std::endl;
    }
    this->num = num;
    this->prime = prime;
}

void FieldElement::repr() const {
    std::cout << "Field Element_" << this->prime << "(" << this->num << ")" << std::endl;
}

bool FieldElement::operator == (FieldElement &ref) { //연산자 오버로딩
    if (&ref == NULL) return false;
    return (this->num == ref.num) && (this->prime == ref.prime);
}

bool FieldElement::operator != (FieldElement &ref) { //Practice 1.1
    if (&ref == NULL) return false;
    return (this->num != ref.num) || (this->prime != ref.prime);
}

FieldElement FieldElement::add(FieldElement &ref) {
    if (this->prime != ref.prime) {
        std::cout << "Cannot add two numbers in different Fields" << std::endl;
    }
    int sum = (this->num + ref.num) % this->prime;
    FieldElement result;
    result.init(sum, this->prime);
    return result;
}

FieldElement FieldElement::sub(FieldElement &ref) {
    if (this->prime != ref.prime) {
        std::cout << "Cannot add two numbers in different Fields" << std::endl;
    }
    int minus = 0;
    if (this->num >= ref.num) {
        minus = (this->num - ref.num) % this->prime;
    } else {
        minus = ((this->num - ref.num) + this->prime) % this->prime;
    }
    FieldElement result;
    result.init(minus, this->prime);
    return result;
}

FieldElement FieldElement::mul(FieldElement &ref) {
    if (this->prime != ref.prime) {
        std::cout << "Cannot add two numbers in different Fields" << std::endl;
    }
    FieldElement result;
    int ans = (this->num * ref.num) % this->prime;
    result.init(ans, this->prime);
    return result;
}

FieldElement FieldElement::power(int exponent) {
    int n = exponent;
    while (n < 0) n += this->prime - 1;
    int ans = pow(this->num, n);
    ans %= this->prime;
    FieldElement result;
    result.init(ans, this->prime);
    return result;
}

FieldElement FieldElement::truediv(FieldElement &ref) {
    if (this->prime != ref.prime) {
        std::cout << "Cannot add two numbers in different Fields" << std::endl;
    }
    int num = pow(ref.num, this->num - 2);
    int ans = this->num * (num % this->prime) % this->prime;
    FieldElement result;
    result.init(ans, this->prime);
    return result;
}