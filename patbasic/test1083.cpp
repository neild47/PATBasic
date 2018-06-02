//
// Created by neild47 on 18-5-20.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

static int map[10000] = {0};

int test1083() {
    int n;
    cin >> n;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        map[abs(i - num)]++;
    }
    for (int i = 9999; i >= 0; i--) {
        if (map[i] > 1) {
            cout << i << " " << map[i] << endl;
        }
    }
    return 0;
}
