#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, sum = 0;
    cin >> x;
    string a;
    cin >> a;

    for (int i = 0; i < x; ++i) {
        string s = a.substr(0, i + 1);

        int s_long = s.size();
        int longest = 0;

        for (int j = 0; j < s_long - 1; ++j) {

            string c = s.substr(0, j + 1);

            c += c;

            string q = c.substr(0, s_long);

            if (s == q) {

                longest = max(longest, j + 1);

            }
        }

        sum += longest;

    }
    cout << sum;
    return 0;
}