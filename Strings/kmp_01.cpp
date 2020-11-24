#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    char a[x], b[y];
    scanf(" %[^\n]%*c", a);
    scanf(" %[^\n]%*c", b);

    int L[x];
    L[0] = 0;
    int k = 0;
    for (int i = 1; i < x; ++i) {
        if (b[i] == b[k]) {
            k++;
        } else {
            while (b[i] != b[k] && k > 0) {
                k = L[k - 1];
            }
        }
        L[i] = k;
    }

    int i = 0;
    k = 0;
    while (i < x) {
        if (a[i] == b[k]) {
            k++;
            i++;
        }
        if (k == y) {
            cout << i - k << "\n";
        }
        if (a[i] != b[k]) {
            if (k != 0) {
                k = L[k - 1];
            } else {
                i++;
            }
        }
    }
    return 0;
}