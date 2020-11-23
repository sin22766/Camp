#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, minN = 1e9, minH = 1e9;
    scanf("%d", &n);
    int height[n + 5], hole[n + 5];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &height[i]);
        minH = min(minH, height[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &hole[i]);
    }

    //Compute
    vector<int> holeCP(hole, hole + n + 5);
    sort(holeCP.begin(), holeCP.end());
    holeCP.erase(unique(holeCP.begin(), holeCP.end()), holeCP.end());

    long long result, minD = 1e18;
    for (auto i:holeCP) {
        if (i > minH) {
            continue;
        }
        result = 0;
        for (int j = 0; j < n; ++j) {
            int temp;
            if (hole[j] >= i) {
                temp = hole[j] - i;
            } else {
                temp = (height[j] - i) + hole[j];
            }
            result += temp;
        }
        if (result < minD) {
            minD = result;
            minN = i;
        }else{
            break;
        }
    }
    cout << minN << " " << minD << "\n";
    return 0;
}
