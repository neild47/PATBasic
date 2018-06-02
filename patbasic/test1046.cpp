//
// Created by neild47 on 18-4-27.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int test1046() {
    int line[4];
    int n;
    cin >> n;
    int jia = 0, yi = 0;

    for (int i = 0; i < n; i++) {
        cin >> line[0] >> line[1] >> line[2] >> line[3];
        int allWin = 0;
        if (line[0] + line[2] == line[1]) {
            yi++;
            allWin++;
        }
        if (line[0] + line[2] == line[3]) {
            jia++;
            allWin++;
        }
        if (allWin == 2) {
            yi--;
            jia--;
        }
    }
    cout << jia << " " << yi << endl;
    return 0;
}
