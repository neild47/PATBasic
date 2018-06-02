//
// Created by neild47 on 18-5-2.
//
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Question {
public:
    int score;
    int total;
    vector<char> ans;
    vector<int> count;

    Question(int score, int total, vector<char> ans) : score(score), total(total), ans(std::move(ans)) {
        count = vector<int>(total, 0);
    }
};

class Error {
public:
    int count;
    int number;
    char choice;

    Error(int count, int number, char choice) : count(count), number(number), choice(choice) {}

    bool operator<(Error &other) {
        if (count != other.count) {
            return count > other.count;
        } else if (number != other.number) {
            return number < other.number;
        } else {
            return choice < other.choice;
        }
    }
};

int test1073() {
    int n, m;
    cin >> n >> m;
    vector<Question> questions;
    questions.reserve(m);
    for (int i = 0; i < m; i++) {
        int s, t, nn;
        cin >> s >> t >> nn;
        vector<char> ans;
        ans.reserve(nn);
        for (int j = 0; j < nn; j++) {
            string c;
            cin >> c;
            ans.push_back(c[0]);
        }
        questions.emplace_back(s, t, ans);
    }
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        int iter = 0;
        double sum = 0;
        for (int j = 0; j < m; j++) {
            while (line[iter] != '(') {
                iter++;
            }
            iter++;
            int count = line[iter] - '0';
            iter++;
            vector<char> check;
            for (int k = 0; k < count; k++) {
                if (!isalpha(line[iter])) {
                    iter++;
                }
                check.push_back(line[iter]);
                iter++;
            }
            bool isFalse = false;

            for (auto cc:check) {
                if (!binary_search(questions[j].ans.begin(), questions[j].ans.end(), cc)) {
                    isFalse = true;
                    questions[j].count[cc - 'a']++;
                }
            }
            for (auto cc:questions[j].ans) {
                if (!binary_search(check.begin(), check.end(), cc)) {
                    questions[j].count[cc - 'a']++;
                }
            }
            if (!isFalse) {
                if (check.size() == questions[j].ans.size()) {
                    sum += questions[j].score;
                } else {
                    sum += questions[j].score / 2.0;
                }
            }
        }
        printf("%.1f\n", sum);
    }

    vector<Error> errors;
    for (int i = 0; i < questions.size(); i++) {
        for (int j = 0; j < questions[i].count.size(); j++) {
            if (questions[i].count[j] != 0) {
                errors.emplace_back(questions[i].count[j], i + 1, 'a' + j);
            }
        }
    }

    if (errors.empty()) {
        cout << "Too simple" << endl;
    } else {
        sort(errors.begin(), errors.end());
        int cc = errors[0].count;
        printf("%d %d-%c\n", errors[0].count, errors[0].number, errors[0].choice);
        int iter = 1;
        while (iter < errors.size() && errors[iter].count == cc) {
            printf("%d %d-%c\n", errors[iter].count, errors[iter].number, errors[iter].choice);
            iter++;
        }
    }
    return 0;
}
