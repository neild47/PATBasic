//
// Created by neild47 on 18-5-2.
//
#include <iostream>
#include <vector>

using namespace std;

int test1074() {
    string s, s1, s2;
    cin >> s >> s1 >> s2;

    vector<int> s_v;
    for (auto i = s.rbegin(); i != s.rend(); i++) {
        if ((*i) != '0') {
            s_v.push_back((*i) - '0');
        } else {
            s_v.push_back(10);
        }
    }
    s_v.push_back(10);
    vector<int> s1_v;
    for (auto i = s1.rbegin(); i != s1.rend(); i++) {
        s1_v.push_back((*i) - '0');
    }
    while (s1_v.size() < s_v.size()) {
        s1_v.push_back(0);
    }
    vector<int> s2_v;
    for (auto i = s2.rbegin(); i != s2.rend(); i++) {
        s2_v.push_back((*i) - '0');
    }
    while (s2_v.size() < s_v.size()) {
        s2_v.push_back(0);
    }

    vector<int> out(s.size() + 1, 0);

    int iter = 0;
    for (; iter < s1_v.size(); iter++) {
//        cout << s1_v[iter] << " " << s2_v[iter] << " " << out[iter] << endl;
        out[iter + 1] += (s1_v[iter] + s2_v[iter] + out[iter]) / s_v[iter];
        out[iter] = (s1_v[iter] + s2_v[iter] + out[iter]) % s_v[iter];
    }

    auto iter0 = out.rbegin();
    while (*iter0 == 0 && iter0 != out.rend()) {
        iter0++;
    }
    if (iter0 == out.rend()) {
        cout << 0 << endl;
    } else {
        while (iter0 != out.rend()) {
            cout << *iter0;
            iter0++;
        }
        cout << endl;
    }
    return 0;
}
