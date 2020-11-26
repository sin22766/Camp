#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main() {
    int n, p, u, e, l;
    scanf("%d%d%d%d", &n, &p, &u, &e);
    vector<pii> graph[n + 5];
    for (int i = 0; i < e; ++i) {
        int q, r, t;
        scanf("%d%d%d", &q, &r, &t);
        graph[q].emplace_back(r, t);
    }

    vector<pii> real_dist;

    for (auto i:graph[p]) {
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        vector<bool> visited(n + 5, false);
        vector<int> dist(n + 5, 1e9);

        pq.emplace(0, i.first, 0);
        dist[i.first] = i.second;

        while (!pq.empty()) {
            int q = get<1>(pq.top());
            int pass = get<2>(pq.top());
            pq.pop();

            for (auto j:graph[q]) {
                int r = j.first;
                int t = j.second;
                if (dist[q] + t < dist[r]) {
                    dist[r] = dist[q] + t;
                    if (r == u) {
                        real_dist.emplace_back(dist[r], pass + 1);
                    } else {
                        pq.emplace(dist[r], r, pass + 1);
                    }
                }
            }
        }
    }

    sort(real_dist.begin(), real_dist.end());
    real_dist.erase(unique(real_dist.begin(), real_dist.end()), real_dist.end());

    /*for (auto j:real_dist) {
        int dist = j.first;
        int path = j.second;

        cout << dist << " " << path << '\n';
    }*/

    scanf("%d", &l);
    for (int i = 0; i < l; ++i) {
        int h;
        scanf("%d", &h);
        int minN = 1e9;
        for (auto j:real_dist) {
            int dist = j.first;
            int path = j.second;

            minN = min(minN, dist + (h * path));
        }
        cout << minN << " ";
    }
    return 0;
}

