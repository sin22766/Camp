#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int dist[25][25];
int dp[25][2000];

int n, m, x, y, k;

int mt_dist(pii point1, pii point2) {
    return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

int TSP(int pos, int mask) {
    if (mask == (1 << (k + 1)) - 1) {
        return dist[pos][0];
    }
    if (dp[pos][mask] != 1e9) {
        return dp[pos][mask];
    }
    int ans = 1e9;
    for (int i = 0; i <= k; ++i) {
        if (i != pos && !(mask & (1 << i))) {
            ans = min(ans, dist[pos][i] + TSP(i, mask | (1 << i)));
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            dist[i][j] = 1e9;
        }
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j <= 2000; ++j) {
            dp[i][j] = 1e9;
        }
    }

    pii point[k];

    for (int i = 0; i <= k; ++i) {
        if (i) {
            int u, v;
            scanf("%d%d", &u, &v);
            point[i] = {u, v};
        } else {
            point[i] = {x, y};
        }
    }

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            dist[i][j] = mt_dist(point[i], point[j]);
        }
    }

    cout << TSP(0, 1) << "\n";

    return 0;
}