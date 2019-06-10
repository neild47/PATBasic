#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> vs;
    vs.assign(nums.begin(), nums.end());
    for (auto num : vs) cout << num << endl;
    return 0;
}
