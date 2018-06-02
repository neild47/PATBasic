//
// Created by neild47 on 18-4-28.
//
#include <iostream>
#include <cmath>

using namespace std;

int test1051() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double n1, n2, n3, n4;
    n1 = r1 * cos(p1);
    n2 = r1 * sin(p1);
    n3 = r2 * cos(p2);
    n4 = r2 * sin(p2);

    double a, b;
    a = n1 * n3 - n2 * n4;
    b = n1 * n4 + n2 * n3;
    if (a < 0 && a >= -0.005) {
        printf("0.00");
    } else {
        printf("%.2f", a);
    }
    if (b >= 0) {
        printf("+%.2fi\n", b);
    } else if (b < 0 && b >= -0.005) {
        printf("+0.00i\n");
    } else {
        printf("%.2fi\n", b);
    }
}
