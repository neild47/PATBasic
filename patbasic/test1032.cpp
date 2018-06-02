//
// Created by neild47 on 18-4-24.
//

#include <iostream>

using namespace std;

#define N 100001

static int mark[N] = {0};

int test1032() {
    int n;
    cin >> n;
    int id, score;

    for (int i = 0; i < n; i++) {
        cin >> id >> score;
        mark[id] += score;
    }

    int maxi = 1;
    for (int i = 2; i < N; i++) {
        if (mark[i] > mark[maxi]) {
            maxi = i;
        }
    }

    cout << maxi << " " << mark[maxi] << endl;
    return 0;
}
