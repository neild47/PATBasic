//
// Created by neild47 on 18-4-5.
//

#include <iostream>
#include <string>

using namespace std;

int test1014() {
    string s1 = "";
    string s2 = "";
    string s3 = "";
    string s4 = "";

    cin >> s1 >> s2 >> s3 >> s4;

    int dayPos = -1;
    int hourPos = -1;
    for (int i = 0; i < s1.length(); i++) {
        if (dayPos == -1 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            dayPos = i;
            i++;
        }
        if (dayPos != -1 && s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s1[i] <= 'N')) {
            hourPos = i;
            break;
        }
    }

    int minPos = -1;
    for (int i = 0; i < s3.length(); i++) {
        if (s3[i] == s4[i] && (s3[i] >= 'a' && s3[i] <= 'z' || s3[i] >= 'A' && s3[i] <= 'Z')) {
            minPos = i;
            break;
        }
    }

    string day = "";
    switch (s1[dayPos]) {
        case 'A':
            day = "MON";
            break;
        case 'B':
            day = "TUE";
            break;
        case 'C':
            day = "WED";
            break;
        case 'D':
            day = "THU";
            break;
        case 'E':
            day = "FRI";
            break;
        case 'F':
            day = "SAT";
            break;
        case 'G':
            day = "SUN";
            break;
    }

    int hour;
    if (s1[hourPos] >= 'A') {
        hour = s1[hourPos] - 'A' + 10;
    } else {
        hour = s1[hourPos] - '0';
    }

    int min = minPos;
    cout << day << " ";
    if (hour < 10) {
        cout << '0';
    }
    cout << hour << ":";
    if (min < 10) {
        cout << '0';
    }
    cout << min << endl;

    return 0;
}

