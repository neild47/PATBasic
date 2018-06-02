//
// Created by neild47 on 18-4-29.
//
#include <iostream>

using namespace std;

int test1056() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp * 10 * (n - 1) + tmp * (n - 1);
    }

    cout << sum << endl;

    return 0;
}

