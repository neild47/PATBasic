//
// Created by neild47 on 18-4-28.
//
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

char m[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int test1048() {
    string s1, s2;
    cin >> s1 >> s2;
    int iters1 = static_cast<int>(s1.size() - 1);
    int iters2 = static_cast<int>(s2.size() - 1);
    int i = 1;
    list<char> ans;
    while (iters1 >= 0 && iters2 >= 0) {
        if (i % 2 == 0) {
            int sub = s2[iters2] - s1[iters1];
            if (sub < 0) {
                sub += 10;
            }
            ans.push_front(m[sub]);
        } else {
            ans.push_front(m[(s1[iters1] + s2[iters2] - 2 * '0') % 13]);
        }
        i++;
        iters1--;
        iters2--;
    }
    if (iters2 < 0) {
        while (iters1 >= 0) {
            if (i % 2 == 0) {
                int sub = '0' - s1[iters1];
                if (sub < 0) {
                    sub += 10;
                }
                ans.push_front(m[sub]);
            } else {
                ans.push_front(m[('0' + s1[iters1] - 2 * '0') % 13]);
            }
            i++;
            iters1--;
        }
    } else {
        while (iters2 >= 0) {
            ans.push_front(s2[iters2]);
            iters2--;
        }
    }
    auto iter = ans.cbegin();
    while (iter != ans.cend()) {
        cout << *iter;
        iter++;
    }
    cout << endl;
    return 0;
}
