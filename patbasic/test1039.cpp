//
// Created by neild47 on 18-4-25.
//

#include <algorithm>
#include <iostream>

using namespace std;

int test1039() {
    int sale[128] = {0};
    int need[128] = {0};

    string s;
    cin >> s;
    for (auto c:s) {
        sale[c]++;
    }

    cin >> s;
    for (auto c:s) {
        need[c]++;
    }

    int more = 0;
    for (int i = '0'; i <= 'z'; i++) {
        sale[i] -= need[i];
        if (sale[i] < 0) {
            more -= sale[i];
        }
    }
    if (more > 0) {
        cout << "No" << " " << more << endl;
    } else {
        int count = 0;
        for (int i = '0'; i <= 'z'; i++) {
            count += sale[i];
        }
        cout << "Yes" << " " << count << endl;
    }
    return 0;
}
