//
// Created by neild47 on 18-4-29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static void split(vector<string> &strings, string &line) {
    int i = 0;
    while (i < line.size()) {
        if (line[i] == '[') {
            string s;
            i++;
            while (line[i] != ']' && i < line.size()) s += line[i++];
            if (line[i] == ']' && i != line.size()) {
                strings.push_back(s);
            }
        }
        i++;
    }
}

int test1052() {
    vector<string> hands, eyes, mouses;
    hands.emplace_back(" ");
    eyes.emplace_back(" ");
    mouses.emplace_back(" ");

    string s;
    getline(cin, s);
    split(hands, s);

    getline(cin, s);
    split(eyes, s);

    getline(cin, s);
    split(mouses, s);

    int n;
    cin >> n;
    int choose[5];
    for (int i = 0; i < n; i++) {
        cin >> choose[0] >> choose[1] >> choose[2] >> choose[3] >> choose[4];
        if (choose[0] >= hands.size() || choose[4] >= hands.size() || choose[1] >= eyes.size() ||
            choose[3] >= eyes.size() || choose[2] >= mouses.max_size() || choose[0] < 1 || choose[1] < 1 ||
            choose[2] < 1 || choose[3] < 1 || choose[4] < 1) {
            cout << "Are you kidding me? @\\/@" << endl;
            continue;
        }
        printf("%s(%s%s%s)%s\n", hands[choose[0]].data(), eyes[choose[1]].data(), mouses[choose[2]].data(),
               eyes[choose[3]].data(),
               hands[choose[4]].data());
    }
}
