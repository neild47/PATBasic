//
// Created by neild47 on 18-4-28.
//
#include <cstdio>
#include <iostream>

using namespace std;

int test1049() {
    int n;
    cin >> n;
    double sum = 0;
    double tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &tmp);
        sum += i * tmp * (n - i + 1);
    }
    printf("%.2lf", sum);
    return 0;
}
