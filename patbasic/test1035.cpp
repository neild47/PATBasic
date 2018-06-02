//
// Created by neild47 on 18-4-24.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

static bool isInsertion(vector<int> &raw, vector<int> &arr) {
    auto dis = is_sorted_until(arr.begin(), arr.end());
    int distance = static_cast<int>(dis - arr.begin());
    for (int i = distance; i < raw.size(); i++) {
        if (raw[i] != arr[i]) return false;
    }
    return true;
}

static void printints(vector<int> &ints) {
    cout << ints[0];
    for (int i = 1; i < ints.size(); i++) {
        cout << " " << ints[i];
    }
    cout << endl;
}

static int test1035() {
    int n;
    cin >> n;
    vector<int> raw, middle;
    raw.reserve(n);
    middle.reserve(n);

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        raw.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        middle.push_back(tmp);
    }

    if (isInsertion(raw, middle)) {
        cout << "Insertion Sort" << endl;
        auto dis = is_sorted_until(middle.begin(), middle.end());
        int ele = static_cast<int>(dis - middle.begin());
        if (ele == middle.size()) {
            printints(middle);
            return 0;
        }
        int i = 0;
        for (; i < ele; i++) {
            if (middle[i] > middle[ele]) {
                break;
            }
        }
        if (i != ele) {
            int elevalue = middle[ele];
            for (int j = ele; j > i; j--) {
                middle[j] = middle[j - 1];
            }
            middle[i] = elevalue;
        }
        printints(middle);
    } else {
        int mergeSize = 2;
        while (mergeSize < middle.size()) {
            auto s = middle.begin();
            auto e = middle.end();
            while (s < e) {
                if (!is_sorted(s, min(s + mergeSize, e))) {
                    goto out;
                }
                s += mergeSize;
            }
            mergeSize <<= 1;
        }
        out:
        mergeSize >>= 1;
        auto s = middle.begin();
        auto e = middle.end();
        while (s < e) {
            inplace_merge(s, min(s + mergeSize, e), min(s + 2 * mergeSize, e));
            s += 2 * mergeSize;
        }
        cout << "Merge Sort" << endl;
        printints(middle);
    }
}
