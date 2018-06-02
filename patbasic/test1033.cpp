//
// Created by neild47 on 18-4-24.
//
#include <iostream>

using namespace std;


int test1033() {
    bool isBad[256] = {false};
    string s;
    getline(cin, s);
    for (auto c:s) {
        isBad[c] = true;
        if (isupper(c)) {
            c = tolower(c);
            isBad[c] = true;
        }
    }
    cin >> s;
    for (auto c:s) {
        if (isBad[c] || isupper(c) && isBad['+']) {
            continue;
        }
        cout << c;
    }
    cout << endl;
    return 0;
}
