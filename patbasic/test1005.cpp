//
// Created by neild47 on 18-4-4.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <set>

using namespace std;

void exch(vector<int> &nums, int i, int j) {
    int val = nums[i];
    nums[i] = nums[j];
    nums[j] = val;
}

int partition(vector<int> &nums, int lo, int hi) {
    if (lo >= hi) return lo;
    int i = lo, j = hi + 1;
    int num = nums[lo];
    while (true) {
        while (nums[++i] < num) if (i == hi) break;
        while (nums[--j] > num) if (j == lo) break;
        if (i >= j) break;
        exch(nums, i, j);
    }
    exch(nums, lo, j);
    return j;
}


void quick_sort(vector<int> &nums, int lo, int hi) {
    if (lo >= hi) return;
    int mid = partition(nums, lo, hi);
    quick_sort(nums, lo, mid - 1);
    quick_sort(nums, mid + 1, hi);
}

void reverse(vector<int> &nums) {
    for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
        exch(nums, i, j);
    }
}

vector<int> getNums() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    return nums;
}

vector<int> calcNoCoverNums(vector<int> &nums) {
    set<int> coverNums;
    for (auto tmp: nums) {
        while (tmp != 1) {
            if (tmp % 2 == 0) {
                tmp = tmp / 2;
            } else {
                tmp = (3 * tmp + 1) / 2;
            }
            coverNums.insert(tmp);
        }
    }
    vector<int> ans;
    for (auto tmp:nums) {
        if (!coverNums.count(tmp)) ans.push_back(tmp);
    }
    return ans;
}

int main() {
    auto nums = getNums();
    vector<int> ans = calcNoCoverNums(nums);
    quick_sort(ans, 0, ans.size() - 1);
    reverse(ans);
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

