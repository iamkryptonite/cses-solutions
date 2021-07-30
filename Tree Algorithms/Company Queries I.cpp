#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up;
map<int,vector<int>> mp;
int n,q,l;

void dfs(int u = 1,int p=-1){
    up[u][0] = p;
    for(int i=1;i<=l;i++){
        if(up[u][i-1]!=-1)
            up[u][i] = up[up[u][i-1]][i-1];
        else
            break;
    }
    
    for(int to:mp[u])
        dfs(to,u);
}

int query(int node,int k){
    for(int i=l;i>=0;i--){
        if(k>=(1<<i) && node!=-1){
            node = up[node][i];
            k -= (1<<i);
        }
    }
    return node;
}


int main(){
    cin >> n >> q;

    l = ceil(log2(n));
    up.assign(n+1,vector<int>(l+1,-1));

    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        mp[p].push_back(i);
    }

    dfs();
    while(q--){
        int u,k;
        cin >> u >> k;
        int ans = query(u,k);
        cout<<ans<<"\n";
    }
}