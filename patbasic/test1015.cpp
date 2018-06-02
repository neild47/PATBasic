//
// Created by neild47 on 18-4-14.
//
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int id;
    int d_score;
    int c_score;
} student;

int n, l, h;

int qcompare(const void *s1, const void *s2) {
    auto *ss1 = static_cast<const student *>(s1);
    auto *ss2 = static_cast<const student *>(s2);
    int i = (ss1->c_score + ss1->d_score) - (ss2->d_score + ss2->c_score);
    if (i != 0) {
        return -i;
    } else {
        if (ss1->d_score != ss2->d_score) {
            return ss2->d_score - ss1->d_score;
        } else {
            return ss1->id - ss2->id;
        }
    }
}

void printStudent(student const &s) {
    printf("%d %d %d\n", s.id, s.d_score, s.c_score);
}

int test1015() {
    scanf("%d%d%d", &n, &l, &h);
    student s1[n], s2[n], s3[n], s4[n];
    int ns1 = 0, ns2 = 0, ns3 = 0, ns4 = 0;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        student s{};
        scanf("%d%d%d", &s.id, &s.d_score, &s.c_score);
        if (s.d_score < l || s.c_score < l) {
            continue;
        }
        count++;
        if (s.d_score >= h && s.c_score >= h) {
            s1[ns1++] = s;
        } else if (s.d_score >= h) {
            s2[ns2++] = s;
        } else if (s.c_score < h && s.d_score >= s.c_score) {
            s3[ns3++] = s;
        } else {
            s4[ns4++] = s;
        }
    }
    qsort(s1, ns1, sizeof(student), qcompare);
    qsort(s2, ns2, sizeof(student), qcompare);
    qsort(s3, ns3, sizeof(student), qcompare);
    qsort(s4, ns4, sizeof(student), qcompare);

    printf("%d\n", count);

    for (const auto &s:s1) {
        printStudent(s);
    }
    for (const auto &s:s2) {
        printStudent(s);
    }
    for (const auto &s:s3) {
        printStudent(s);
    }
    for (const auto &s:s4) {
        printStudent(s);
    }

    return 0;
}
