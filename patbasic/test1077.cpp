//
// Created by neild47 on 18-5-8.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int test1077() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int teacherMark;
        cin >> teacherMark;
        int sum = 0;
        int count = 0;
        int mark = 0;
        int max = -1;
        int min = 1000;
        for (int j = 1; j < n; j++) {
            cin >> mark;
            if (mark >= 0 && mark <= m) {
                count++;
                sum += mark;
                if (mark > max) {
                    max = mark;
                }
                if (mark < min) {
                    min = mark;
                }
            }
        }
//        cout << "max:" << max << " min:" << min << endl;
        sum -= max;
        sum -= min;
        count -= 2;
        cout << (int) round((sum * 1.0 / count + teacherMark) / 2.0) << endl;
    }
    return 0;
}
