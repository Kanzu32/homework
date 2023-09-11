#include <cassert>

#include "minmax.h"
#include "minmax.cpp"
#include "svg.h"
#include "svg.cpp"

void testMinMaxPositive();
void testMinMaxNegative();
void testMinMaxOne();
void testMinMaxZero();
void testOpacity();
void testOpacityLow();

int main() {
    testMinMaxPositive();
    testMinMaxNegative();
    testMinMaxOne();
    testMinMaxZero();
    testOpacity();
    cout << "UNIT-TESTS: OK" << endl;
}

void testOpacity() {
    double res = getOpacity(5, 10);
    assert(res == 0.5);
}

void testOpacityZero() {
    double res = getOpacity(5, 0);
    assert(res == 0);
}

void testOpacityLow() {
    double res = getOpacity(5, 1000);
    assert(res == 0.2);
}

void testMinMaxPositive() {
    double min = 0;
    double max = 0;
    findMinMax(vector<double>{1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void testMinMaxNegative() {
    double min = 0;
    double max = 0;
    findMinMax(vector<double>{-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void testMinMaxOne() {
    double min = 0;
    double max = 0;
    findMinMax(vector<double>{3}, min, max);
    assert(min == 3);
    assert(max == 3);
}

void testMinMaxZero() {
    double min = 0;
    double max = 0;
    findMinMax(vector<double>{}, min, max);
    assert(min == 0);
    assert(max == 0);
}

