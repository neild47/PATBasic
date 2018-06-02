//
// Created by neild47 on 18-4-30.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool su[10001];

static void getSu() {
    for (int i = 0; i < 10001; i++) {
        su[i] = true;
    }

    for (int i = 2; i < 10001; i++) {
        if (su[i]) {
            int tmp = i + i;
            while (tmp < 10001) {
                su[tmp] = false;
                tmp += i;
            }
        }
    }
}

static int test1059() {
    getSu();
    int n;
    cin >> n;
    map<string, int> id;
    string tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        id[tmp] = i;
    }

    cin >> n;
    set<string> already;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        string m;
        if (already.count(tmp) != 0) {
            m = "Checked";
        } else {
            if (id[tmp] == 0) {
                m = "Are you kidding?";
            } else {
                already.insert(tmp);
                if (id[tmp] == 1) {
                    m = "Mystery Award";
                } else if (su[id[tmp]]) {
                    m = "Minion";
                } else {
                    m = "Chocolate";
                }
            }
        }
        cout << tmp << ": " << m << endl;
    }
}
