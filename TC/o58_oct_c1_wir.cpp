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
        s.push(i);
    }

    sort(table, table + n);

    for (int i = 0; i < m; ++i) {
        int q;
        scanf("%d", &q);
        int temp = (int) (upper_bound(table, table + n, q) - table);
        cout << n - temp << "\n";
    }

    return 0;
}
