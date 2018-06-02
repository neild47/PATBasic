//
// Created by neild47 on 18-5-1.
//

#include <iostream>

using namespace std;

int test1066() {
    int m, n, low, up, k;
    scanf("%d%d%d%d%d", &m, &n, &low, &up, &k);
    int tmp;
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        if (tmp >= low && tmp <= up) {
            printf("%03d", k);
        } else {
            printf("%03d", tmp);
        }
        for (int j = 1; j < n; j++) {
            scanf("%d", &tmp);
            if (tmp >= low && tmp <= up) {
                printf(" %03d", k);
            } else {
                printf(" %03d", tmp);
            }
        }
        printf("\n");
    }
    return 0;
}
