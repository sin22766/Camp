#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int mp[15][105];
int dp[15][105];
pii parent[15][105];

pii checker[3] = {{0,  -1},
                  {-1, -1},
                  {1,  -1}};

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i <= m + 5; ++i) {
        for (int j = 0; j <= n + 5; ++j) {
            if (i > 0 && j > 0 && i <= m && j <= n) {
                scanf("%d", &mp[i][j]);
                if(j==1){
                    dp[i][j] = mp[i][j];
                }
            }
            dp[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            int ans = 1e9;
            pii p;
            for (auto k:checker) {
                int u = k.first;
                int v = k.second;

                int x = (i + u <= 0) ? n : (i + u > n) ? 1 : i + u;
                int y = j + v;
                if (dp[x][y] + mp[i][j] <= ans) {
                    ans = dp[x][y] + mp[i][j];
                    p = {x, y};
                }
            }
            cout << "_______\n";
            parent[i][j] = p;
            dp[i][j] = ans;
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << parent[i][j].first << "," << parent[i][j].second << " ";
        }
        cout << "\n";
    }

    stack<int> s;
    int minN = 1e9, u;
    for (int i = 1; i <= m; ++i) {
        if (dp[i][n] < minN) {
            minN = dp[i][n];
            u = i;
        }
    }

    cout << "Min is " << dp[u][n] << "\n";
    cout << "Pass1\n";

    int i = parent[u][n].first, j = parent[u][n].second;
    s.push(u);
    while (j != 1) {
        s.push(i);
        i = parent[i][j].first;
        j = parent[i][j].second;
    }
    cout << i << " ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n" << dp[u][n];

    return 0;
}

