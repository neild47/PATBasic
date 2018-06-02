//
// Created by neild47 on 18-5-8.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static inline string add(string &s1) {
    auto s1_iter = s1.rbegin();
    auto s2_iter = s1.begin();
    char out[1024] = {0};
    int iter = 1020;
    int c = 0;
    while (s1_iter != s1.rend() && s2_iter != s1.end()) {
        out[iter] = static_cast<char>((*s1_iter - '0' + *s2_iter - '0' + c) % 10 + '0');
        c = (*s1_iter - '0' + *s2_iter - '0' + c) / 10;
        iter--;
        s1_iter++;
        s2_iter++;
    }
    if (c != 0) {
        out[iter--] = c + '0';
    }
    return string(&out[iter + 1]);
}

static bool isPalindromic(string &s) {
    int pos = 0;
    int len = s.length();
    while (pos < len / 2) {
        if (s[pos] != s[len - 1 - pos]) {
            return false;
        }
        pos++;
    }
    return true;
}

int test1079() {
    string num;
    cin >> num;
    if (isPalindromic(num)) {
        cout << num << " is a palindromic number." << endl;
    } else {
        bool isOk = false;
        for (int i = 0; i < 10; i++) {
            cout << num << " + ";
            for (auto iter = num.rbegin(); iter != num.rend(); iter++) {
                cout << *iter;
            }
            num = add(num);
            cout << " = " << num << endl;
            if (isPalindromic(num)) {
                cout << num << " is a palindromic number." << endl;
                isOk = true;
                break;
            }
        }
        if (!isOk) {
            cout << "Not found in 10 iterations." << endl;
        }
    }
    return 0;
}
