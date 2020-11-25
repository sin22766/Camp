#include "doll.h"
#include <bits/stdc++.h>

using namespace std;

void create_circuit(int M, vector<int> A) {
    int N = A.size();

    vector<int> cnt(M, 0);

    for (int i:A) {
        cnt[i]++;
    }
    int size[N];
    for (int i = 1; i <= N; ++i) {
        size[i] = (int) log2(cnt[i]) * 4;
        cout << size[i] << " ";
    }
}