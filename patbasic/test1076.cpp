//
// Created by neild47 on 18-5-8.
//
#include <iostream>
#include <sstream>

using namespace std;

int test1076() {
    int n;
    string line;
    getline(cin, line);
    n = stoi(line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream stringstream1(line);
        string s;
        stringstream1 >> s;
        while (s[2] != 'T') {
            stringstream1 >> s;
        }
        cout << (s[0] - 'A' + 1);
    }
    cout << endl;
    return 0;
}
