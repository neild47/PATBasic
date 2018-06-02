//
// Created by neild47 on 18-4-26.
//

#include <iostream>

using namespace std;

int test1040() {
    long sump = 0;
    long sumpa = 0;
    long sumpat = 0;

    char c;
    while (scanf("%c", &c) && c != '\n') {
        switch (c) {
            case 'P':
                sump++;
                break;
            case 'A':
                sumpa += sump;
                break;
            case 'T':
                sumpat += sumpa;
                break;
        }
    }
    cout << sumpat % 1000000007 << endl;
    return 0;
}
