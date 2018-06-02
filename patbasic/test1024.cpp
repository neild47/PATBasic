//
// Created by neild47 on 18-4-19.
//
#include <cstdio>
#include <cstring>
#include <cstdlib>

//+1.23400E-03
static char num[10048];

int test1024() {
    scanf("%s", num);
    int idx = 0;
    int sign = 1;
    if (num[idx] == '-') {
        sign = -1;
    }

    idx++;

    int reidx = 0;
    while (num[idx] != 'E' && num[idx] != '\0') {
        if (num[idx] == '.') {
            idx++;
            continue;
        }
        num[reidx] = num[idx];
        reidx++;
        idx++;
    }

    idx++;

    int e = atoi((const char *) &num[idx]);
    num[reidx] = '\0';

    if (sign == -1) {
        printf("-");
    }
    if (e < 0) {
        e = -e;
        printf("0.");
        for (int i = 1; i < e; ++i) {
            printf("0");
        }
    } else {
        int id = 0;
        for (; id < e && num[id] != '\0'; ++id) {
            printf("%c", num[id]);
            e--;
        }
        if (e > 0) {
            for (int i = 0; i < e; ++i) {
                printf("0");
            }
        } else {
            printf(".");
            for (; num[id] != '\0'; ++id) {
                printf("%c", num[id]);
            }
        }
    }
    printf("\n");
    return 0;
}
