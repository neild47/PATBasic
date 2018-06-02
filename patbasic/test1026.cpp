//
// Created by neild47 on 18-4-23.
//
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

int test1026() {
    long s, e;
    cin >> s >> e;
    long seconds = (int) round((e - s) / 100.0);
    int hour = seconds / 3600;
    seconds %= 3600;
    int min = seconds / 60;
    seconds %= 60;
    printf("%02d:%02d:%02d\n", hour, min, seconds);
    return 0;
}
