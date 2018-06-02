//
// Created by neild47 on 18-4-29.
//
#include <iostream>

using namespace std;

int test1057() {
    int sum = 0;
    string s;
    getline(cin, s);
    for (auto c :s) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = tolower(c);
            }
            sum += c - 'a' + 1;
        }
    }

    int count1 = 0;
    int count0 = 0;

    while (sum != 0) {
        if (sum % 2 == 0) {
            count0++;
        } else {
            count1++;
        }
        sum /= 2;
    }
    cout << count0 << " " << count1 << endl;
    return 0;
}

