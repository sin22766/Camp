#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int building[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &building[i]);
    }

    int table[n];
    stack<int> s;
    s.push(0);
    table[0] = 0;
    for (int i = 1; i < n; ++i) {
        while (!s.empty() && building[i] < building[s.top()]) {
            s.pop();
        }
        int before = (s.empty()) ? 0 : s.top();
        int dif = building[i] - building[before];
        table[i] = max(dif, table[before]);
    }

    for (int i = 0; i < n; ++i) {
        cout << table[i] << " ";
    }

    return 0;
}
