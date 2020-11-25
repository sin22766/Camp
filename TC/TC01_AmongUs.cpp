#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<string, int> mapper;
    for (int i = 1; i <= n; ++i) {
        string temp;
        cin >> temp;
        mapper[temp] = i;
    }

    vector<int> arr;
    for (int i = 1; i <= n; ++i) {
        string temp;
        cin >> temp;
        int value = mapper[temp];
        if (value != 0) {
            arr.push_back(value);
        }
    }

    vector<int> lis;

    for (auto i:arr) {
        int number = 0;
        int l = 0;
        int r = (int) lis.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            cout << "Mid : " << mid << "\n";

            if (lis[mid] >= i) {
                r = mid - 1;
                number = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << "Size : " << lis.size() << "\n";

        cout << number << "\n";

        if (number >= lis.size()) {
            lis.push_back(i);
        } else {
            lis[number] = i;
        }
    }

    cout << lis.size();

    return 0;
}