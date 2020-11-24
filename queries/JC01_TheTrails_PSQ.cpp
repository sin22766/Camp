#include<bits/stdc++.h>

using namespace std;

int tree[200005];
int n, m;

int maxInTree(int a, int b) {
    a += n;
    b += n;
    int maxN = 0;
    while (a <= b) {
        if (a % 2) {
            maxN = max(maxN, tree[a++]);
        }
        if (!(b % 2)) {
            maxN = max(maxN, tree[b--]);
        }

        a /= 2;
        b /= 2;
    }
    return maxN;
}

void add(int k, int x) {
    k += n;
    tree[k] = x;
    for (k = k / 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    int height[n + 5], temp;

    //Range Max Query

    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        add(i, temp);
    }

    //Prefix Sum Query
    long long qs[n + 1];
    qs[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i - 1];
    }

    for (int i = 0; i < m; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        cout << maxInTree(s, t) << " " << qs[t + 1] - qs[s] << "\n";
    }
    return 0;
}