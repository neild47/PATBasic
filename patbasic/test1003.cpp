//
// Created by neild47 on 18-4-4.
//

#include <iostream>

using namespace std;

bool solution(const char *chars) {
    int pos_P = -1;
    int pos_T = -1;

    int i = 0;
    for (; chars[i] != '\0'; ++i) {
        if (chars[i] == 'P') {
            if (pos_P != -1) {
                return false;
            } else {
                pos_P = i;
            }
        } else if (chars[i] == 'A') {
        } else if (chars[i] == 'T') {
            if (pos_T != -1) {
                return false;
            } else {
                pos_T = i;
            }
        } else {
            return false;
        }
    }
    int numA_mid = pos_T - pos_P - 1;
    int numA_left = pos_P;
    int numA_right = i - pos_T - 1;
    if (numA_mid < 1) {
        return false;
    }
    if (numA_left == 0 && numA_right == 0) {
        return true;
    } else if (numA_left == 0 || numA_right == 0) {
        cout << "asdasdsadasdasddsa" << endl;
        return false;
    }
    return (numA_right - numA_left) / numA_left == numA_mid - 1;

}

int test1003() {
    int n;
    cin >> n;
    char chars[100] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> chars;
        cout << (solution(chars) ? "YES" : "NO") << endl;
    }
    return 0;
}
