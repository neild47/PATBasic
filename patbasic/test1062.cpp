//
// Created by neild47 on 18-4-30.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

static long gcd(long a, long b) {
    if (a == 0 || b == 0) {
        return 1;
    }
    long x = a > b ? a : b;
    long y = a > b ? b : a;
    long r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

static long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

int test1062() {
    string n1, n2;
    long k;

    cin >> n1 >> n2 >> k;
    long a1, b1, a2, b2;
    sscanf(n1.data(), "%ld/%ld", &a1, &b1);
    sscanf(n2.data(), "%ld/%ld", &a2, &b2);

    long tmp = lcm(b1, b2);
    a1 *= tmp / b1;
    b1 = tmp;
    a2 *= tmp / b2;
    b2 = tmp;

    if (a1 * b2 > a2 * b1) {
        long tmp = a1;
        a1 = a2;
        a2 = tmp;

        tmp = b1;
        b1 = b2;
        b2 = tmp;
    }

    long iter = 1;
    while (iter * 1.0 / k <= a1 * 1.0 / b1) {
        iter++;
    }

    vector<string> s;
    while (iter * 1.0 / k < a2 * 1.0 / b2) {
        if (gcd(iter, k) == 1) {
            stringstream ss;
            ss << iter << "/" << k;
            s.push_back(ss.str());
        }
        iter++;
    }

    if (s.size() > 0) {
        cout << s[0];
        for (int i = 1; i < s.size(); i++) {
            cout << " " << s[i];
        }
    }
    cout << endl;
    return 0;
}
