#include <iostream>

using namespace std;

int test1001() {
    int n;
    cin >> n;
    int count = 0;
    while (n != 1) {
        count++;
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (3 * n + 1) / 2;
        }
    }
    cout << count << endl;
    return 0;
}