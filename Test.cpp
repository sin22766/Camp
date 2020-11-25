#include <bits/stdc++.h>

using namespace std;

void solver(int size, int tree[], bool state[], int i) {
    if (!state[i]) {
        solver(size, tree, state, i * 2);
    } else {
        solver(size, tree, state, i * 2 + 1);
    }
}

void create_circuit(int M, vector<int> A) {
    int N = A.size();
    int size = (int) log2(N) * 2;

    int tree[size];
    bool state[size];
    fill_n(state, size, 0);


}

int main() {
    create_circuit(4, {1, 2, 1, 3, 1, 4});
    return 0;
}