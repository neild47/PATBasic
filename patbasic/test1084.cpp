//
// Created by neild47 on 18-5-20.
//
#include<cstdio>
#include<iostream>

using namespace std;

int test1084() {
    int n, cnt = 1;
    string s;
    cin >> s >> n;
    while (cnt < n) {
        char pre = s[0];
        int tempcnt = 1;
        string temp;
        temp += s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != pre) {
                temp += to_string(tempcnt);
                temp += s[i];
                tempcnt = 1;
                pre = s[i];
            } else {
                tempcnt++;
            }
        }
        s = temp + to_string(tempcnt);
        cout << s << endl;
        cnt++;
    }
    cout << s;
    return 0;
}
