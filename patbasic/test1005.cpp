//
// Created by neild47 on 18-4-4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

class Num {
public:
    int num;
    bool isCover = false;

    bool operator>(const Num &num1) const {
        return this->num > num1.num;
    }

    bool operator<(const Num &num1) const {
        return this->num < num1.num;
    }

    bool operator==(const Num &num1) const {
        return this->num == num1.num;
    }
};

int test1005() {
    size_t num;
    cin >> num;
    vector<Num> nums(num);
    for (int i = 0; i < num; ++i) {
        Num tmpnum;
        cin >> tmpnum.num;
        nums[i] = tmpnum;
    }
//
    sort(nums.begin(), nums.end(), less<Num>());

    for (const Num &item:nums) {
        int tmp = item.num;
        while (tmp != 1) {
            if (tmp % 2 == 0) {
                tmp = tmp / 2;
            } else {
                tmp = (3 * tmp + 1) / 2;
            }
            Num tmpn;
            tmpn.num = tmp;
            auto a = find(nums.begin(), nums.end(), tmpn);
            if (a != nums.end()) {
                (*a).isCover = true;
            }
        }
    }
    stringstream stringstream1;
    for (auto j = nums.rbegin(); j != nums.rend(); ++j) {
        if (!(*j).isCover) {
            stringstream1 << (*j).num << " ";
        }
    }
    string s = stringstream1.str();
    cout << s.substr(0, s.length() - 1) << endl;
}

