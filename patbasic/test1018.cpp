//
// Created by neild47 on 18-4-18.
//

#include <cstdio>

static char findMax(int *w) {
    int max = 2;
    if (w[2] >= w[1] && w[2] >= w[0]) {
        max = 2;
    } else if (w[1] >= w[0] && w[1] >= w[2]) {
        max = 1;
    } else {
        max = 0;
    }
    switch (max) {
        case 2:
            return 'B';
        case 1:
            return 'C';
        case 0:
            return 'J';
    }
}

int test1018() {
    int a[3] = {0};//s p f
    int wa[3] = {0};//j c b
    int wb[3] = {0};

    int n;
    scanf("%d", &n);
    char c1[2], c2[2];
    for (int i = 0; i < n; ++i) {
        scanf("%s %s", c1, c2);
        if (c1[0] == c2[0]) {
            a[1]++;
        } else if (c1[0] == 'C' && c2[0] == 'J') {
            a[0]++;
            wa[1]++;
        } else if (c2[0] == 'C' && c1[0] == 'J') {
            wb[1]++;
            a[2]++;
        } else if (c1[0] == 'B' && c2[0] == 'C') {
            wa[2]++;
            a[0]++;
        } else if (c2[0] == 'B' && c1[0] == 'C') {
            wb[2]++;
            a[2]++;
        } else if (c1[0] == 'J' && c2[0] == 'B') {
            wa[0]++;
            a[0]++;
        } else if (c2[0] == 'J' && c1[0] == 'B') {
            wb[0]++;
            a[2]++;
        }
    }

    printf("%d %d %d\n", a[0], a[1], a[2]);
    printf("%d %d %d\n", a[2], a[1], a[0]);
    printf("%c %c", findMax(wa), findMax(wb));
    return 0;
}
