#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

pii rail[20];
int minN = 1e9,n;

void backtrack(int num,int ext){
    if(num <= 0){
        minN = min(minN,ext);
    }
    for (int i = 0; i < n; ++i) {
        
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        rail[i] = {s, t};
    }
    return 0;
}
