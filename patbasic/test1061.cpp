//
// Created by neild47 on 18-4-30.
//
#include <iostream>

using namespace std;

int test1061() {
    int n, m;
    cin >> n >> m;
    int mark[m];
    int ans[m];
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        mark[i] = tmp;
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        ans[i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (ans[j] == tmp) {
                sum += mark[j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}

