//
// Created by neild47 on 18-5-8.
//
#include <iostream>
#include <sstream>

using namespace std;

int test1078() {
    string line;
    getline(cin, line);
    char cmd = line[0];
    getline(cin, line);
    if (cmd == 'C') {
        char c = line[0];
        int pos = 0;
        while (line[pos] != '\0') {
            int count = 0;
            while (line[pos] != '\0' && line[pos] == c) {
                count++;
                pos++;
            }
            if (count > 1) {
                cout << count << c;
            } else {
                cout << c;
            }
            c = line[pos];
        }
        cout << endl;
    } else {
        int pos = 0;
        while (line[pos] != '\0') {
            int count = 0;
            while (isdigit(line[pos])) {
                count *= 10;
                count += line[pos] - '0';
                pos++;
            }
            if (count == 0) {
                cout << line[pos];
            } else {
                for (int i = 0; i < count; i++) {
                    cout << line[pos];
                }
            }
            pos++;
        }
    }
    return 0;
}


//5T2h4is i5s a3 te4st CA3a as10Z
