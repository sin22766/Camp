#include <bits/stdc++.h>

using namespace std;

int student[10000000];
int dp[10000000][10];
int elevator[15], staff[15], s_time[15];
int n, m, x;

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &elevator[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &staff[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", &student[i]);
    }

    for (int i = 0; i < x; ++i) {
        scanf("%d", &s_time[i]);
    }

    sort(elevator, elevator + n);
    sort(student, student + n);

    for (int i = 0; i < n; ++i) {
        elevator[i] -= student[i];
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < n; ++j) {

        }
    }

    return 0;
}
