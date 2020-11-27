#include <bits/stdc++.h>

using namespace std;
using pii = pair<long long, long long>;

long long intersect(pii f_point, pii s_point) {
    long long y = (f_point.second * f_point.first) - (s_point.second * s_point.first);
    long long x = y / (f_point.second - s_point.second);
    return x;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<pii> v_temp, v_new;

    int query[m];

    // S,T
    for (int i = 0; i < n; ++i) {
        int s, t;
        scanf("%d%d", &t, &s);
        v_temp.emplace_back(t, s);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &query[i]);
    }

    sort(v_temp.begin(), v_temp.end());
    sort(query, query + m);
    v_new.push_back(v_temp[0]);

    //Filter Same Velocity
    for (int i = 1; i < n; ++i) {
        if (!v_new.empty() && v_temp[i].second <= v_new.back().second) {
            continue;
        }
        v_new.push_back(v_temp[i]);
    }

    //Filter Non wining
    long long x_pre = -1;
    n = v_new.size();
    v_temp.clear();
    v_temp.push_back(v_new[0]);
    for (int i = 1; i < n; ++i) {
        long long x_intersect = intersect(v_new[i], v_new[i - 1]);
        if (x_pre != -1) {
            if (x_pre < x_intersect) {
                v_temp.push_back(v_new[i - 1]);
            }
        }
        x_pre = max(x_intersect, x_pre);
    }
    v_temp.push_back(v_new.back());

    n = v_temp.size();
    for (int q:query) {
        int i;
        for (i = 0; i < n && v_temp[i].second * (q - v_temp[i].first) <
                             v_temp[i + 1].second * (q - v_temp[i + 1].first); ++i);
        cout << max((long long) 0, v_temp[i].second * (q - v_temp[i].first)) << "\n";
    }

    return 0;
}