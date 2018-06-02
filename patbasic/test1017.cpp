//
// Created by neild47 on 18-4-18.
//

#include <cstdio>

int test1017() {
    char a[1024];
    int b;
    scanf("%s%d", a, &b);

    char q[1024] = {0};
    int idx_q = 0;

    int idx_a = 0;
    int tmp = 0;
    while (a[idx_a] != '\0') {
        tmp *= 10;
        tmp += a[idx_a] - '0';
        q[idx_q++] = (char) (tmp / b + '0');
        tmp %= b;
        idx_a++;
    }
    idx_q = 0;
    while (q[idx_q] == '0' && q[idx_q + 1] != '\0') {
        idx_q++;
    }

    printf("%s %d", &q[idx_q], tmp);
    return 0;
}
