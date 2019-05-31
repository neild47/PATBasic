#include <iostream>

using namespace std;


int getCallatz(int);

int main() {
    int n;
    cin >> n;
    cout << getCallatz(n) << endl;
    return 0;
}


int getCallatz(int n) {
    int cnt = 0;
    while (n != 1 && ++cnt) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
    }
    return cnt;
}