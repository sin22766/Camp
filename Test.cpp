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

    scanf("%d", &l);
    if (l > 10000) {
        vector<pii> real_dist;
        for (auto i:graph[p]) {
            priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
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
    } else {
        for (int i = 0; i < l; ++i) {
            int h;
            scanf("%d", &h);

            priority_queue<pii, vector<pii>, greater<pii>> pq;
            vector<int> dist(n + 5, 1e9);

            pq.emplace(0, p);
            dist[p] = 0;

            while (!pq.empty()) {
                int q = get<1>(pq.top());
                pq.pop();

                if (q == u) {
                    cout << dist[q] << " ";
                    break;
                }

                for (auto j:graph[q]) {
                    int r = j.first;
                    int t = j.second;
                    if (q != p) {
                        if (dist[q] + t + h < dist[r]) {
                            dist[r] = dist[q] + h + t;
                            pq.emplace(dist[r], r);
                        }
                    } else {
                        if (dist[q] + t < dist[r]) {
                            dist[r] = dist[q] + t;
                            pq.emplace(dist[r], r);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

