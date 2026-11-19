#define UNIT_TESTING
#define Z 7 // Можна змінити на 3 або 10, щоб протестувати другу гілку

#include <iostream>
#include <cassert>
#include <cmath>

// Шлях до основного файлу проєкту
#include "../../lab9.2.1/lab9.2.1/main.cpp"

using namespace std;

void test_calc_w()
{
#if IN_RANGE(Z)
    // Для Z = 7, x = 2: min(2, 7) * max(2 + 7, 2 * 7) = 2 * 14 = 28
    double x = 2.0;
    double expected = 28.0;
    assert(fabs(calc_w(x) - expected) < 1e-9);
    cout << "Branch (5 < z < 10) test passed!" << endl;
#else
    // Для Z = 3, x = -2: max(|-2 - 3|, 3)^2 = max(5, 3)^2 = 25
    // Для Z = 10, x = 4: max(|4 - 10|, 10)^2 = max(6, 10)^2 = 100
    double x = (Z <= 5) ? -2.0 : 4.0;
    double expected = (Z <= 5) ? 25.0 : 100.0;
    assert(fabs(calc_w(x) - expected) < 1e-9);
    cout << "Branch (z <= 5 or z >= 10) test passed!" << endl;
#endif
}

int main()
{
    test_calc_w();
    cout << "All unit tests passed!" << endl;
    return 0;
}
