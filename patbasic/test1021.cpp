//
// Created by neild47 on 18-4-18.
//

#include <cstdio>
#include <cstring>

char nums[1024];

int test1021() {
    int map[10] = {0};
    scanf("%s", nums);
    for (int i = 0; i < strlen(nums); ++i) {
        map[nums[i] - '0']++;
    }

    for (int j = 0; j < 10; ++j) {
        if (map[j] == 0) {
            continue;
        }
        printf("%d:%d\n", j, map[j]);
    }
    return 0;
}
