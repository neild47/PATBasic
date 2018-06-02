//
// Created by neild47 on 18-4-29.
//
#include <iostream>

using namespace std;


bool isLegle(string &s) {
    int i = 0;
    if (s[i] == '-') i++;
    for (; i < s.size(); i++) {
        if (s[i] == '.') {
            int c = 0;
            i++;
            for (; i < s.size(); i++) {
                if (!isdigit(s[i])) {
                    return false;
                } else {
                    c++;
                }
            }
            return c <= 2;
        } else {
            if (!isdigit(s[i])) {
                return false;
            }
        }
    }
    return true;
}

int test1054() {
    int n;
    cin >> n;
    string s;
    int legelNum = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (isLegle(s)) {
            double tmpn;
            sscanf(s.data(), "%lf", &tmpn);
            if (tmpn > 1000 || tmpn < -1000) {
                printf("ERROR: %s is not a legal number\n", s.data());
            } else {
                sum += tmpn;
                legelNum++;
            }
        } else {
            printf("ERROR: %s is not a legal number\n", s.data());
        }
    }
    if (legelNum == 0) {
        cout << "The average of 0 numbers is Undefined" << endl;
    } else {
        if (legelNum == 1) {
            printf("The average of %d number is %.2f\n", legelNum, sum);
        } else {
            printf("The average of %d numbers is %.2f\n", legelNum, sum / legelNum);
        }
    }
    return 0;
}
