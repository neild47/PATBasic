//
// Created by neild47 on 18-4-26.
//
#include <iostream>
#include <map>
#include <sstream>

using namespace std;
static string di[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
static string gao[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


int test1044() {
    map<string, int> dimap;
    map<string, int> gaomap;
    for (int i = 1; i <= 12; i++) {
        dimap[di[i]] = i;
        gaomap[gao[i]] = i;
    }
    int n;
    string s;
    getline(cin, s);
    n = atoi(s.data());
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (isdigit(s[0])) {//earth -> mar
            int num = atoi(s.data());
            if (num > 12) {
                if (num % 13 != 0) {
                    cout << gao[num / 13] << " " << di[num % 13] << endl;
                } else {
                    cout << gao[num / 13] << endl;
                }
            } else {
                cout << di[num] << endl;
            }
        } else {//mar -> earth
            stringstream ss(s);
            ss >> s;
            int num = 0;
            if (gaomap[s]) {
                num += 13 * gaomap[s];
                ss >> s;
            }
            num += dimap[s];
            cout << num << endl;
        }
    }
    return 0;
}
