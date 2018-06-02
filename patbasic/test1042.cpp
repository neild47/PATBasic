//
// Created by neild47 on 18-4-26.
//
#include <iostream>
#include <cmath>

using namespace std;

int count[128] = {0};

int test1042() {
    char c;
    while (scanf("%c", &c) && c != '\n') {
        if (isalpha(c)) {
            count[c]++;
        }
    }

    int maxi = 'A';
    for (int i = 'A'; i <= 'Z'; i++) {
        int m = count[i] + count[i + 32];
        if (m > count[maxi] + count[maxi + 32]) {
            maxi = i;
        }
    }
    printf("%c %d\n", maxi + 32, count[maxi] + count[maxi + 32]);
    return 0;
}
