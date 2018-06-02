//
// Created by neild47 on 18-5-1.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int test() {
    string line;
    while (getline(cin, line)) {
        vector<char> ans1;
        stack<vector<char>> ans2;
        ans2.push(vector<char>());
        bool insertBack = true;
        for (auto c:line) {
            if (c == '[') {
                insertBack = false;
                ans2.push(vector<char>());
                continue;
            }
            if (c == ']') {
                insertBack = true;
                continue;
            }
            if (insertBack) {
                ans1.push_back(c);
            } else {
                ans2.top().push_back(c);
            }
        }
        while (!ans2.empty()) {
            auto ss = ans2.top();
            ans2.pop();
            for (auto c:ss) {
                cout << c;
            }
        }

        for (auto c:ans1) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
