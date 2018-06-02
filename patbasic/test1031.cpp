//
// Created by neild47 on 18-4-24.
//
#include <algorithm>
#include <iostream>

using namespace std;

static int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
static char check_arr[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

static bool check(string &s) {
    int cnt = 0;
    for (int i = 0; i < 17; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
        cnt += weight[i] * (s[i] - '0');
    }
    cnt %= 11;
    return s[17] == check_arr[cnt];
}

int test1031() {
    int n;
    cin >> n;
    string s;
    int cnt_bad = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!check(s)) {
            cout << s << endl;
            cnt_bad++;
        }
    }
    if (cnt_bad == 0) {
        cout << "All passed" << endl;
    }
    return 0;
}
