//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <string>

using namespace std;
static string strings[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};

int test1002() {
    string s;
    cin >> s;
    const char *s_data = s.data();
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        sum += s.data()[i] - '0';
    }

    char result[10] = {0};
    sprintf(result, "%d", sum);

    cout << strings[result[0] - '0'];
    for (int i = 1; result[i] != '\0'; ++i) {
        cout << " " << strings[result[i] - '0'];
    }
    return 0;
}

