#include <bits/stdc++.h>

using namespace std;

int dp[2][4][4][4][4];
int food[100005];
// Food / 1st Mine Last/ 1st Mine LastLast/ 2nd Mine Last/ 2nd Mine LastLast/

int check_ore(int f, int s, int t) {
    int cnt = 0;
    for (int i = 1; i <= 3; ++i) {
        if(f == i || s == i || t == i)
            cnt++;
    }
    return cnt;
}

int main() {
    int n;
    char temp[100005];
    scanf("%d%s", &n, temp + 1);

    for (int i = 1; i <= n; ++i) {
        food[i] = (temp[i] == 'M') ? 1 : (temp[i] == 'F') ? 2 : 3;
    }

    //None = 0, M1, F2, B3

    for (int x = n + 1; x >= 1; --x) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        if (x == n+1) {
                            dp[x % 2][i][j][k][l] = 0;
                        } else {
                            dp[x % 2][i][j][k][l] = max(check_ore(food[x], i, j) + dp[(x % 2) ^ 1][food[x]][i][k][l],
                                                        check_ore(food[x], k, l) + dp[(x % 2) ^ 1][i][j][food[x]][k]);
                        }
                    }
                }
            }
        }
    }

    cout << dp[1][0][0][0][0];
    return 0;
}

