#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up;
map<int,vector<int>> mp;
vector<int> tin,tout;
int timer = 0;
int n,q,l;

void dfs(int u = 1,int p = 1){
    tin[u] = ++timer;
    up[u][0] = p;

    for(int i=1;i<=l;i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    
    for(int to:mp[u])
        dfs(to,u);

    tout[u] = ++timer;
}

bool is_boss(int u,int v){
    if(tin[u] <= tin[v] && tout[u] >= tin[v])
        return true;
    return false;
}

int query(int u,int v){
    if(is_boss(u,v))
        return u;
    if(is_boss(v,u))
        return v;
    for(int i=l;i>=0;i--){
        if(!is_boss(up[u][i],v))
            u = up[u][i];
    }
    return up[u][0];    
}


int main(){
    cin >> n >> q;

    l = ceil(log2(n));
    up.assign(n+1,vector<int>(l+1,-1));
    tin.assign(n+1,0);
    tout.assign(n+1,0);

    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        mp[p].push_back(i);
    }

    dfs();
    while(q--){
        int u,v;
        cin >> u >> v;
        int ans = query(u,v);
        cout<<ans<<"\n";
    }
}