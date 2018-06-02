//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char *su;
static int num;

void getSu() {
    for (int i = 2; i <= num; ++i) {
        int tmp = i * 2;
        while (tmp <= num) {
            if (!su[tmp]) {
                su[tmp] = true;
            }
            tmp += i;
        }
    }
}

int test1007() {
    cin >> num;
    su = new char[num + 1];
    memset(su, 0, sizeof(bool) * (num + 1));
    getSu();

    int n = 0;
    for (int i = 2; i <= num - 2; ++i) {
        if (!su[i] && !su[i + 2]) {
            n++;
        }
    }
    cout << n << endl;
}
