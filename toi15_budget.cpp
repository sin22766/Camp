#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

class edge {
public:
    int u, v, w;
};

bool comparer(edge a, edge b) {
    return a.w < b.w;
}

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void merge(int parent[], int i, int j) {
    parent[find(parent, j)] = find(parent, i);
}

int main() {
    int b, e;
    scanf("%d%d", &b, &e);
    vector<edge> edgeList, result;
    int parent[b + 5];
    for (int i = 0; i < b + 5; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < e; ++i) {
        int s, t, l, r;
        scanf("%d%d%d%d", &s, &t, &l, &r);
        edgeList.push_back({s, t, l});
        if (r == 1) {
            merge(parent, s, t);
        }
    }
    sort(edgeList.begin(), edgeList.end(), comparer);
    int p;
    scanf("%d", &p);
    vector<pii> project;
    for (int i = 0; i < p; ++i) {
        int c, d;
        scanf("%d%d", &c, &d);
        project.emplace_back(d, c);
    }
    sort(project.begin(), project.end());

    for (auto i:edgeList) {
        int u = i.u;
        int v = i.v;
        int w = i.w;
        if (find(parent, u) != find(parent, v)) {
            result.push_back({u, v, w});
            merge(parent, u, v);
        }
    }
    vector<int> r1, r2;
    for (auto i:project) {
        r1.push_back(i.first);
        r2.push_back(i.second);
    }
    int c_result = 0;
    for (auto i:result) {
        for (auto j:project) {
            if(i.w < j.second){
                c_result += j.first;
                break;
            }
        }
    }
    cout << c_result;
    return 0;
}

