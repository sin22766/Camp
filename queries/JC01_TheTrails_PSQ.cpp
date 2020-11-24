#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sqrN;
    scanf("%d%d", &n, &m);
    sqrN = (int) sqrt(n);


    //Range Max Query
    int height[n + 5], rmq[sqrN];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &height[i]);
        if (i % sqrN == 0) {
            rmq[i / sqrN] = height[i];
        }
        if (rmq[i / sqrN] < height[i]) {
            rmq[i / sqrN] = height[i];
        }
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

        long long maxAns = height[s], sumAns;

        sumAns = qs[t + 1] - qs[s];

        while (s < t && (s % sqrN)) {
            if (height[s] > maxAns) {
                maxAns = height[s];
            }
            ++s;
        }
        while (s + sqrN <= t) {
            if (rmq[s/sqrN] > maxAns) {
                maxAns = rmq[s/sqrN];
            }
            ++s;
        }
        while (s <= t) {
            if (height[s] > maxAns) {
                maxAns = height[s];
            }
            ++s;
        }
        cout << maxAns << " " << sumAns << "\n";
    }
    return 0;
}