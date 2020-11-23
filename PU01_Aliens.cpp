#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    vector<pii> i_point;

    for(int i = 0; i < n; ++i)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        i_point.emplace_back(r,c);
    }

    sort(i_point.begin(),i_point.end());

    int maxN = 0;
    return 0;
}
