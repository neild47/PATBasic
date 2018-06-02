//
// Created by neild47 on 18-5-20.
//

#include <iostream>

using namespace std;

int test1081() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s.length() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }
        bool isHaveBadChar = false;
        int alphaCounter = 0;
        int digidCounter = 0;
        for (auto c : s) {
            if (isalpha(c)) {
                alphaCounter++;
            } else if (isdigit(c)) {
                digidCounter++;
            } else if (c == '.') {

            } else {
                isHaveBadChar = true;
                break;
            }
        }
        if (isHaveBadChar) {
            cout << "Your password is tai luan le." << endl;
            continue;
        }

        if (digidCounter == 0) {
            cout << "Your password needs shu zi." << endl;
        } else if (alphaCounter == 0) {
            cout << "Your password needs zi mu." << endl;
        } else {
            cout << "Your password is wan mei." << endl;
        }
    }
    return 0;
}
