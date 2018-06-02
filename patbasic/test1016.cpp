//
// Created by neild47 on 18-4-18.
//

#include <cstdio>

int test1016() {
    long a, b;
    int da, db;
    scanf("%ld%d%ld%d", &a, &da, &b, &db);
    long pa = 0;
    long pb = 0;
    while (a != 0) {
        auto tmp = a % 10;
        if (tmp == da) {
            pa *= 10;
            pa += tmp;
        }
        a /= 10;
    }
    while (b != 0) {
        auto tmp = b % 10;
        if (tmp == db) {
            pb *= 10;
            pb += tmp;
        }
        b /= 10;
    }

    printf("%ld\n", pa + pb);
}
