//
// Created by neild47 on 18-4-28.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int test1050() {
    int N;
    cin >> N;
    int m, n;
    n = static_cast<int>(sqrt(N));
    while (N % n != 0) {
        n--;
    }
    m = N / n;

    vector<int> ints;
    ints.reserve(N);
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        ints.push_back(tmp);
    }

    sort(ints.begin(), ints.end(), std::greater<int>());

    vector<vector<int> *> vectors;
    for (int i = 0; i <= m + 1; i++) {
        vector<int> *v;
        if (i == 0 || i == m + 1) {
            v = new vector<int>(n + 2, 1);
        } else {
            v = new vector<int>(n + 2, 0);
            (*v)[0] = 1;
            (*v)[n + 1] = 1;
        }
        vectors.push_back(v);
    }

    if (N == 1) {
        (*vectors[1])[1] = ints[0];
    } else {
        int iteri = 1;
        int iterj = 1;
        int iterv = 0;
        int speedi = 0;
        int speedj = 1;
        int nn = N;
        while (nn > 0) {
            (*vectors[iteri])[iterj] = ints[iterv];
            if (speedj == 1 && (*vectors[iteri])[iterj + 1] != 0) {
                speedi = 1;
                speedj = 0;
            } else if (speedi == 1 && (*vectors[iteri + 1])[iterj] != 0) {
                speedi = 0;
                speedj = -1;
            } else if (speedj == -1 && (*vectors[iteri])[iterj - 1] != 0) {
                speedi = -1;
                speedj = 0;
            } else if (speedi == -1 && (*vectors[iteri - 1])[iterj] != 0) {
                speedi = 0;
                speedj = 1;
            }
            iteri += speedi;
            iterj += speedj;
            iterv++;
            nn--;
        }
    }

    for (int i = 1; i <= m; i++) {
        auto v = vectors[i];
        cout << (*v)[1];
        for (int j = 2; j <= n; j++) {
            cout << " " << (*v)[j];
        }
        cout << endl;
    }
    return 0;
}
