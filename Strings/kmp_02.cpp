#include<bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    char a[x];
    scanf(" %[^\n]%*c", a);

    int L[x];
    L[0] = 0;
    int k = 0;
    for (int i = 1; i < x; ++i) {
        if (a[i] == a[k]) {
            k++;
        } else {
            while (a[i] != a[k] && k > 0) {
                k = L[k - 1];
            }
        }
        L[i] = k;
    }

    for (int l = 1; l <= x; ++l) {
        int i = 0;
        k = 0;
        while (i < l) {
            cout << a[i];
            if (a[i] == a[k]) {
                k++;
                i++;
            }
            if (k == l) {
                cout << i << "\n";
            }
            if (a[i] != a[k]) {
                if (k != 0) {
                    k = L[k - 1];
                } else {
                    i++;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}