#define UNIT_TESTING

#include <iostream>
#include <cassert>
#include <cmath>


#include "../../lab9.1/lab9.1/var.cpp"
#include "../../lab9.1/lab9.1/dod.cpp"
#include "../../lab9.1/lab9.1/sum.cpp"
#include "../../lab9.1/lab9.1/main.cpp"

using namespace std;
using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

void test_dod() {
    x = 0.5;
    n = 1;
    a = x; // a0 = 0.5
    dod();
    // a1 = -x^2 / 2 = -0.125
    assert(fabs(a - (-0.125)) < 1e-9);
    cout << "test_dod passed!" << endl;
}

void test_sum() {
    x = 0.5;
    e = 1e-6;
    sum();
    assert(fabs(s - log(x + 1)) < 1e-5);

    x = -0.5;
    e = 1e-6;
    sum();
    assert(fabs(s - log(x + 1)) < 1e-5);

    x = 0.0;
    e = 1e-6;
    sum();
    assert(fabs(s - 0.0) < 1e-9);

    cout << "test_sum passed!" << endl;
}

int main() {
    test_dod();
    test_sum();
    cout << "All unit tests passed!" << endl;
    return 0;
}
