//
// Created by neild47 on 18-5-2.
//
#include <iostream>

using namespace std;

int test1071() {
    int t, k;
    cin >> t >> k;
    for (int i = 0; i < k; i++) {
        int num, guess, tt, num2;
        cin >> num >> guess >> tt >> num2;
        if (tt > t) {
            printf("Not enough tokens.  Total = %d.\n", t);
        } else if (num2 < num && guess == 0 || num2 > num && guess == 1) {
            t += tt;
            printf("Win %d!  Total = %d.\n", tt, t);
        } else {
            t -= tt;
            printf("Lose %d.  Total = %d.\n", tt, t);
            if (t == 0) {
                printf("Game Over.");
                break;
            }
        }
    }
    return 0;
}
