//
// Created by neild47 on 18-4-30.
//

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int test1060c() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    sort(arr, arr + n, [](int x, int y) { return x > y; });

    int iter = 0;
    while (iter != n) {
        if (arr[iter] <= iter + 1) {
            break;
        }
        iter++;
    }
    if (iter == n) {
        cout << n << endl;
    } else {
        cout << iter << endl;
    }
    return 0;
}
