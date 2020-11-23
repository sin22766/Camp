#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<int> graph[n + 5];
    for(int i = 0; i < m; ++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 0; i < q; ++i)
    {
        int s,e,l,r;
        scanf("%d%d%d%d",&s,&e,&l,&r);

        queue<int> q,q2;
        q.push(s);
        bool human[n+5],evil[n+5];
        fill_n(human,n+5,false);
        fill_n(evil,n+5,false);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            if(human[u])
            {
                continue;
            }
            human[u] = true;

            for(auto j:graph[u])
            {
                if(j >= l)
                {
                    q.push(j);
                }
            }
        }
        q2.push(e);
        bool able = false;
        while(!q2.empty())
        {
            int u = q2.front();
            q2.pop();
            if(human[u])
            {
                able = true;
                break;
            }

            if(evil[u])
            {
                continue;
            }
            evil[u] = true;

            for(auto j:graph[u])
            {
                if(j <= r)
                {
                    q2.push(j);
                }
            }
        }
        (able)? cout << 1 : cout << 0;
        cout << "\n";
    }
    return 0;
}
