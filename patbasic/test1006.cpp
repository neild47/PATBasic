//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int test1006() {
    int num;
    cin >> num;
    stringstream stringstream1;
    if (num >= 100) {
        int tmp = num / 100;
        for (int i = 0; i < tmp; ++i) {
            stringstream1 << 'B';
        }
        num = num % 100;
    }
    if (num >= 10) {
        int tmp = num / 10;
        for (int i = 0; i < tmp; ++i) {
            stringstream1 << 'S';
        }
        num = num % 10;
    }
    if (num > 0) {
        for (int i = 1; i <= num; ++i) {
            stringstream1 << i;
        }
    }
    cout << stringstream1.str();
}


