//
// Created by neild47 on 18-5-1.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test1070() {
    vector<int> ts;
    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ts.push_back(tmp);
    }

    sort(ts.begin(), ts.end());

    double sum = ts[0];
    for (int i = 1; i < ts.size(); i++) {
        sum = sum / 2 + ts[i] / 2.0;
    }
    int ss = static_cast<int>(sum);
    cout << ss << endl;
    return 0;
}
