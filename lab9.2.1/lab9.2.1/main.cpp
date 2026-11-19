#include <iostream>
#include "macros.h"

using namespace std;

// Функція обчислення w з умовною компіляцією гілок
double calc_w(double x)
{
    double w;

#if IN_RANGE(Z)
    // Гілка 1: 5 < z < 10 -> min(x, z) * max(x + z, x * z)
    double m1 = MIN(x, Z);
    double m2 = MAX(x + Z, x * Z);
    w = m1 * m2;
#else
    // Гілка 2: z <= 5 або z >= 10 -> max^2(|x - z|, z)
    double m = MAX(ABS(x - Z), Z);
    w = SQR(m);
#endif

    return w;
}

#ifndef UNIT_TESTING
int main()
{
    puts("Lab 9.2.1. Using macros and preprocessor directives");
    double x, w;
    char ch;

    do
    {
        PRINTI(Z);
        cout << "Input x = ";
        cin >> x;
        PRINTR(x);

#if IN_RANGE(Z)
        puts("Compiled branch: 5 < z < 10");
#else
        puts("Compiled branch: z <= 5 or z >= 10");
#endif

        w = calc_w(x);
        PRINTR(w);

        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
#endif
