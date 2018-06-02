//
// Created by neild47 on 18-4-29.
//
#include <iostream>

using namespace std;

int test1053() {
    int maybeNum = 0, mustNum = 0;
    int numPeople, D;
    double threshold;
    cin >> numPeople >> threshold >> D;

    for (int i = 0; i < numPeople; i++) {
        int day;
        cin >> day;
        int numLowerThreshold = 0;
        double tmp;
        for (int j = 0; j < day; j++) {
            cin >> tmp;
            if (tmp < threshold) {
                numLowerThreshold++;
            }
        }
        if (numLowerThreshold > day / 2) {
            if (day > D) {
                mustNum++;
            } else {
                maybeNum++;
            }
        }
    }
    printf("%.1f%% %.1f%%\n", maybeNum * 100.0 / numPeople, mustNum * 100.0 / numPeople);
    return 0;
}
