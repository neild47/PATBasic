//
// Created by neild47 on 18-4-23.
//

#include <iostream>

using namespace std;

static int getN(int count) {
    count--;
    if (count == 0) {
        return 1;
    }
    int iter = 1;
    while (count > 0) {
        iter += 2;
        count -= 2 * iter;
    }
    return iter - 2;
}

int test1027() {
    int count;
    string sc;
    cin >> count >> sc;
    char c = sc.data()[0];

    int n = getN(count);
    int already = 0;

    for (int i = n; i >= 1; i -= 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << c;
            already++;
        }
        cout << endl;
    }

    for (int i = 3; i <= n; i += 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << c;
            already++;
        }
        cout << endl;
    }
    cout << count - already << endl;
    return 0;
}
