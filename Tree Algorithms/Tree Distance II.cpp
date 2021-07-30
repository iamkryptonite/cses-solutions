#include <bits/stdc++.h>
#define ll long long int
using namespace std;


map<int,vector<int>> mp;

vector<ll> c; //no of sub children 
vector<ll> d; //sum of distances


void dfs(int u=1,int p=-1){
    for(int to:mp[u]){
        if(to!=p){
            dfs(to,u);
            d[u] += 1 + c[to] + d[to];
            c[u] += 1 + c[to];
        }
    }
}

void solve(int u=1,int p=-1){
    if(p!=-1){
        ll child = c[p] - 1 - c[u];
        ll dist = d[p] - 1 - c[u] - d[u];
        c[u] += 1 + child;
        d[u] += 1 + dist + child;
    }
    for(int to:mp[u]){
        if(to!=p){
            solve(to,u);
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    d.assign(n+1,0);
    c.assign(n+1,0);

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs();
    solve();

    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
}