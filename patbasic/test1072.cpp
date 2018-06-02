//
// Created by neild47 on 18-5-2.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int test1072() {
    int n, m;
    cin >> n >> m;
    set<int> checks;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        checks.insert(tmp);
    }

    int find_student = 0;
    int find_things = 0;

    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name >> num;
        vector<int> finded;
        for (int j = 0; j < num; j++) {
            int tmp;
            cin >> tmp;
            if (checks.count(tmp)) {
                finded.push_back(tmp);
            }
        }
        if (!finded.empty()) {
            find_student++;
            find_things += finded.size();
            cout << name << ": ";
            printf("%04d", finded[0]);
            for (int j = 1; j < finded.size(); j++) {
                printf(" %04d", finded[j]);
            }
            cout << endl;
        }
    }
    cout << find_student << " " << find_things << endl;
    return 0;
}
