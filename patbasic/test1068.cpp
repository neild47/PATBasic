//
// Created by neild47 on 18-5-1.
//
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class Pixel {
public:
    int value;
    int x, y;

    Pixel(int value, int x, int y) : value(value), x(x), y(y) {}

//    bool operator<(const Pixel &other) {
//        return this->value < other.value;
//    }
};

static bool cmp(const Pixel &a, const Pixel &b) {
    return a.value < b.value;
}

static int test1068() {
    int m, n, t;
    cin >> n >> m >> t;
    int img[m][n];
    map<Pixel, int, bool (*)(const Pixel &, const Pixel &)> count_map(cmp);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            img[i][j] = tmp;
            count_map[Pixel(tmp, i, j)]++;
        }
    }

    auto iter = count_map.begin();
    vector<Pixel> ans;
    while (iter != count_map.end()) {
        if ((*iter).second == 1) {
            int x = (*iter).first.x;
            int y = (*iter).first.y;
            bool isFlase = false;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x + i < 0 || y + j < 0 || x + i >= m || y + j >= n || (i == 0 && j == 0)) {
                        continue;
                    }
                    if (abs(img[x + i][y + j] - img[x][y]) <= t) {
                        isFlase = true;
                        break;
                    }
                }
            }
            if (!isFlase) {
                ans.push_back((*iter).first);
            }
        }
        iter++;
    }

    if (ans.empty()) {
        cout << "Not Exist" << endl;
    } else if (ans.size() > 1) {
        cout << "Not Unique" << endl;
    } else {
        printf("(%d, %d): %d\n", ans[0].y + 1, ans[0].x + 1, ans[0].value);
    }
    return 0;
}
