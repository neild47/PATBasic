//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <sstream>

using namespace std;

int test1008() {
    int num, l;
    cin >> num >> l;
    l = l % num;

    auto *n = new int[num];
    for (int i = 0; i < num; ++i) {
        cin >> n[i];
    }
    stringstream stringstream1;
    for (int j = num - l; j < num; ++j) {
        stringstream1 << n[j] << " ";
    }
    for (int k = 0; k < num - l; ++k) {
        stringstream1 << n[k] << " ";
    }
    cout << stringstream1.str().substr(0, stringstream1.str().length() - 1) << endl;
    return 0;
}
