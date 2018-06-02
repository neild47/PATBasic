//
// Created by neild47 on 18-4-30.
//
#include <iostream>
#include <cmath>

using namespace std;

int test1063() {
    long m = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        long tmpm = n1 * n1 + n2 * n2;
        if (tmpm > m) {
            m = tmpm;
        }
    }

    double s = sqrt(m);
    printf("%.2f\n", s);
    return 0;
}
