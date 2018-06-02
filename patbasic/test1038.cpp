//
// Created by neild47 on 18-4-25.
//
#include <iostream>

using namespace std;

static int mm[101] = {0};

int test1038() {
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mm[tmp]++;
    }

    cin >> n;
    cin >> tmp;
    cout << mm[tmp];
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        cout << " " << mm[tmp];
    }
    cout << endl;
    return 0;
}
