#pragma once
#include <cstdio>

// Значення Z для умовної компіляції (змінюй, щоб перевірити іншу гілку)
#ifndef Z
#define Z 7
#endif

// Макроси математичних операцій
#define SQR(a)    ((a) * (a))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a)    (((a) < 0) ? -(a) : (a))

// Логічний макрос перевірки діапазону 5 < z < 10
#define IN_RANGE(z) ((z) > 5 && (z) < 10)

// Макроси виведення (#w перетворює ім'я змінної на рядок)
#define PRINTI(w) puts("Control output:"); \
                  printf(#w " = %d\n", (int)(w))

#define PRINTR(w) puts("Result:"); \
                  printf(#w " = %.4f\n", (double)(w))
