//
// Created by neild47 on 18-5-20.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class School {
public:
    string name;
    int count;
    double score;

    explicit School(string s1) {
        name = std::move(s1);
        count = 0;
        score = 0;
    }

    School() {
        count = 0;
        score = 0;
    }

    bool operator<(const School &s2) {
        if ((int) score != (int) s2.score) {
            return (int) s2.score < (int) score;
        } else if (count != s2.count) {
            return count < s2.count;
        } else {
            return name < s2.name;
        }
    }
};


int test1085() {
    char id[10], schoolName[10];
    int score;
    int n;
    cin >> n;
    unordered_map<string, School> schools;

    for (int i = 0; i < n; i++) {
        cin >> id >> score >> schoolName;
        for (int c = 0; schoolName[c] != '\0'; c++) {
            schoolName[c] = static_cast<char>(tolower(schoolName[c]));
        }

        if (schools.count(schoolName) == 0) {
            schools.insert(make_pair(schoolName, School(string(schoolName))));
        }

        schools[schoolName].count++;
        if (id[0] == 'A') {
            schools[schoolName].score += score;
        } else if (id[0] == 'B') {
            schools[schoolName].score += score / 1.5;
        } else {
            schools[schoolName].score += 1.5 * score;
        }
    }

    vector<School> ans;
    for (auto &s:schools) {
        ans.push_back(s.second);
    }

    sort(ans.begin(), ans.end());

    int size = ans.size();
    cout << size << endl;
    School &older = ans[0];
    int rank = 1;
    cout << rank << " " << older.name << " " << (int) older.score << " " << older.count << endl;
    for (int i = 1; i < size; i++) {
        if ((int) ans[i].score == (int) older.score) {
        } else {
            rank = i + 1;
        }
        cout << rank << " " << ans[i].name << " " << (int) ans[i].score << " " << ans[i].count << endl;
        older = ans[i];
    }
    return 0;
}

