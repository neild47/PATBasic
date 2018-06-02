//
// Created by neild47 on 18-4-25.
//
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int test1036() {
    int width;
    string s;
    cin >> width >> s;
    char c = s[0];
    auto height = static_cast<int>(round(width * 0.5));

    for (int i = 0; i < width; i++) {
        cout << c;
    }
    cout << endl;

    for (int i = 2; i < height; i++) {
        cout << c;
        for (int j = 2; j < width; j++) {
            cout << " ";
        }
        cout << c << endl;
    }

    for (int i = 0; i < width; i++) {
        cout << c;
    }
    cout << endl;
    return 0;
}
