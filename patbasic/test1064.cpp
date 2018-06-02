//
// Created by neild47 on 18-4-30.
//
#include <iostream>
#include <set>

using namespace std;


int test1064() {
    set<int> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        int sum = 0;
        while (tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        ans.insert(sum);
    }

    cout << ans.size() << endl;
    cout << *ans.begin();
    auto iter = ans.begin();
    iter++;
    while (iter != ans.end()) {
        cout << " " << *iter;
        iter++;
    }
    cout << endl;
    return 0;
}
