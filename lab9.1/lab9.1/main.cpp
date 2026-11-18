#include <iostream>
#include <cmath>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

#ifndef UNIT_TESTING
int main() {
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> e;
    cout << endl;

    cout << "Table of values for ln(x + 1)" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|" << setw(9) << "x" << " |"
         << setw(14) << "ln(x + 1)" << " |"
         << setw(14) << "S" << " |"
         << setw(8) << "n" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + 1e-9) {
        sum();
        cout << "|" << setw(9) << fixed << setprecision(2) << x << " |"
             << setw(14) << setprecision(6) << log(x + 1) << " |"
             << setw(14) << setprecision(6) << s << " |"
             << setw(8) << n + 1 << " |" << endl;
        x += dx;
    }
    cout << "------------------------------------------------------" << endl;

    return 0;
}
#endif
