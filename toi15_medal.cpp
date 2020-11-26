#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int people[n], podium[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &people[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &podium[i]);
    }
    sort(people, people + n);
    sort(podium, podium + n, greater<int>());

    for (int i = 0; i < n; ++i) {
        people[i] += podium[i];
    }
    sort(people, people + n);

    long long move = 0;
    for (int i = 1; i < n; ++i) {
        move += abs(people[i] - people[i - 1]);
    }
    cout << move;
    return 0;
}