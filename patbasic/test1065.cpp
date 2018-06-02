//
// Created by neild47 on 18-4-30.
//
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int test1065() {
    map<string, string> couple;
    vector<string> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        couple.insert(make_pair(s1, s2));
        couple.insert(make_pair(s2, s1));
    }

    cin >> n;
    vector<string> input;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    sort(input.begin(), input.end());
    for (string &s:input) {
        if (couple.count(s) == 0 || !binary_search(input.begin(), input.end(), couple[s])) {
            ans.push_back(s);
        }
    }

    cout << ans.size() << endl;
    if (!ans.empty()) {
        auto iter = ans.begin();
        cout << *iter;
        while (++iter != ans.end()) {
            cout << " " << *iter;
        }
        cout << endl;
    }
    return 0;
}
