//
// Created by neild47 on 18-4-19.
//
#include <cstdio>

int test1023() {
    int count[10] = {0};
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &count[i]);
    }

    int idx = 1;
    while (count[idx] == 0 && idx < 10) {
        idx++;
    }
    if (idx == 10) {
        printf("0\n");
        return 0;
    }

    printf("%d", idx);
    count[idx]--;
    for (int i = 0; i < count[0]; ++i) {
        printf("0");
    }
    count[0] = 0;
    for (; idx < 10; idx++) {
        while (count[idx] > 0) {
            printf("%d", idx);
            count[idx]--;
        }
    }

    printf("\n");

    return 0;
}
