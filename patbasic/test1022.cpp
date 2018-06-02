//
// Created by neild47 on 18-4-18.
//
#include <cstring>
#include <cstdio>

int test1022() {
    long a, b;
    int order;
    scanf("%ld%ld%d", &a, &b, &order);
    a = a + b;
    if (order == 10 || a == 0) {
        printf("%ld\n", a);
        return 0;
    }
    char out[256] = {0};
    int idx = 254;
    while (a > 0) {
        out[idx] = static_cast<char>(a % order + '0');
        a /= order;
        idx--;
    }
    printf("%s\n", &out[idx + 1]);
    return 0;
}
