//
// Created by neild47 on 18-5-1.
//
#include <iostream>
#include <string>

using namespace std;

int test1067() {
    string ans;
    int n;
    cin >> ans >> n;
    string test;
    getline(cin, test);
    while (true) {
        if (n == 0) {
            cout << "Account locked" << endl;
            break;
        }
        getline(cin, test);
        if (test == "#") {
            break;
        }
        if (test == ans) {
            cout << "Welcome in" << endl;
            break;
        }
        cout << "Wrong password: " << test << endl;
        n--;
    }
    return 0;
}
