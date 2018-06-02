//
// Created by neild47 on 18-5-1.
//
#include <iostream>
#include <set>

using namespace std;

int test1069() {
    int m, n, s;
    cin >> m >> n >> s;
    set<string> ans;
    string name;
    for (int i = 1; i <= m; i++) {
        cin >> name;
        if (i >= s && (i - s) % n == 0) {
            if (ans.count(name) != 0) {
                s++;
            } else {
                cout << name << endl;
                ans.insert(name);
            }
        }
    }

    if (ans.empty()) {
        cout << "Keep going..." << endl;
    }
    return 0;
}
