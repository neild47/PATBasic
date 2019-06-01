//
// Created by neild47 on 18-4-4.
//

#include <iostream>

using namespace std;


bool isPass(string &s) {
    int pIdx = -1, tIdx = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'P') {
            if (pIdx == -1) {
                pIdx = i;
            } else {
                return false;
            }
        } else if (s[i] == 'T') {
            if (tIdx == -1) {
                tIdx = i;
            } else {
                return false;
            }
        } else if (s[i] != 'A') return false;
    }
    return (tIdx - pIdx - 1) > 0 && (tIdx - pIdx - 1) * pIdx == s.size() - tIdx - 1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << (isPass(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
