//
// Created by neild47 on 18-5-20.
//
#include <iostream>

using namespace std;

static inline double dis(int x, int y) {
    return x * x + y * y;
}

int test1082() {
    string bestId = "", badId = "";
    double bestDis = 10000000, badDis = -1;
    int n;
    cin >> n;
    int x, y;
    string tmpId;
    for (int i = 0; i < n; i++) {
        cin >> tmpId >> x >> y;
        if (x > 100 || x < -100 || y > 100 || y < -100) {
            continue;
        }
        double tmpDis = dis(x, y);
        if (tmpDis < bestDis) {
            bestId = tmpId;
            bestDis = tmpDis;
        }
        if (tmpDis > badDis) {
            badId = tmpId;
            badDis = tmpDis;
        }
    }
    if (bestId.empty()) {
        cout << endl;
    } else {
        cout << bestId << " " << badId << endl;
    }
    return 0;
}
//15806381997 15806381997 15806381997
