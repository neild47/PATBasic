//
// Created by neild47 on 18-4-24.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int test1030() {
    int n, p;
    cin >> n >> p;
    vector<long> ints;
    ints.reserve(n);
    long tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ints.push_back(tmp);
    }

    sort(ints.begin(), ints.end());
    int maxn = 0;
    int mini = 0;
    int maxi = 0;
    while (mini < ints.size()) {
        while (ints[maxi] <= ints[mini] * p && maxi < ints.size()) {
            maxi++;
        }
        if (maxi - mini > maxn) {
            maxn = maxi - mini;
        }
        if (maxi == ints.size()) {
            break;
        }
        mini++;
    }
    cout << maxn << endl;
    return 0;
}
