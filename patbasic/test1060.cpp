//
// Created by neild47 on 18-4-30.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int test1060() {
    map<int, int> distanceToCount;
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (distanceToCount.count(tmp) == 0) {
            distanceToCount[tmp] = 0;
        }
        distanceToCount[tmp]++;
    }

    auto iter = distanceToCount.rbegin();
    auto olditer = iter;
    iter++;

    while (iter != distanceToCount.rend()) {
        (*iter).second += (*olditer).second;
        olditer = iter;
        iter++;
    }

    iter = distanceToCount.rbegin();
    olditer = iter;
    while (iter != distanceToCount.rend()) {
//        cout << (*iter).first << " " << ((*iter).second) << " " << *iter2 << endl;
        if ((*iter).second > (*iter).first) {
            break;
        }
        olditer = iter;
        iter++;
    }
    int dis = min((*olditer).first, (*olditer).second);
    if (iter == distanceToCount.rend()) {
        cout << dis << endl;
    } else {
        int tian = min((*iter).second, (*iter).first);
        cout << max(tian, dis) << endl;
    }
    return 0;
}
