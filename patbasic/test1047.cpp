//
// Created by neild47 on 18-4-27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test1047() {
    int mm[1001] = {0};
    int n;
    cin >> n;
    string s;
    int team, per, score;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sscanf(s.data(), "%d-%d", &team, &per);
        cin >> score;
        mm[team] += score;
    }

    int num = max_element(mm, mm + 1001) - mm;
    cout << num << " " << mm[num] << endl;
    return 0;
}
