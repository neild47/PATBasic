//
// Created by neild47 on 18-4-26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test1045() {
    int n;
    cin >> n;
    vector<int> ints;
    vector<bool> isPrimaryArr;
    ints.reserve(n);
    isPrimaryArr.reserve(n);

    int tmp;
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ints.push_back(tmp);
        isPrimaryArr.push_back(max < tmp);
        if (max < tmp) {
            max = tmp;
        }
    }

    int min = INT32_MAX;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (min < ints[i] && isPrimaryArr[i]) {
            isPrimaryArr[i] = false;
        } else if (isPrimaryArr[i]) {
            ans.push_back(ints[i]);
        }
        if (min > ints[i]) {
            min = ints[i];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (!ans.empty()) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    } else {
        cout << endl;
    }
    return 0;
}

