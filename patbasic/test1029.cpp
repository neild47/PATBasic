//
// Created by neild47 on 18-4-24.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int test1029() {
    string row, type;
    cin >> row >> type;
    int count[256] = {0};

    for (auto c: row) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        count[c]++;
    }

    for (auto c: type) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        count[c]--;
    }

    set<char> badkeys;
    for (auto c: row) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        if (count[c] != 0) {
            if (badkeys.count(c) == 0) {
                badkeys.insert(c);
                cout << c;
            }
        }
    }
    cout << endl;
    return 0;
}
