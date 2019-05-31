//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string readNum(int n) {
    string numToStr[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    if (n == 0) return numToStr[0];
    vector<int> vs;
    while (n) {
        vs.push_back(n % 10);
        n /= 10;
    }
    string s = numToStr[vs.back()];
    vs.pop_back();
    while (!vs.empty()) {
        s += " " + numToStr[vs.back()];
        vs.pop_back();
    }
    return s;
}


int getSum(string s) {
    int sum = 0;
    for (auto c : s) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    string str;
    cin >> str;
    cout << readNum(getSum(str)) << endl;
    return 0;
}
