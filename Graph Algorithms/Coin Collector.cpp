#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map
#define ll long long int

u_map<int,vector<int>> mp,mpr,mp2;
u_map<int,ll> scc;
u_map<int,ll> dp;
vector<bool> vis;
vector<int> v;
vector<ll> used,comp,cost;

void dfs1(int u){
    vis[u] = true;

    for(int i:mp[u]){
        if(!vis[i])
            dfs1(i);
    }

    used.push_back(u);
}

void dfs2(int u,int p){
    vis[u] = true;
    scc[p] += cost[u];
    comp[u] = p;

    for(int i:mpr[u]){
        if(!vis[i])
            dfs2(i,p);
    }
}

ll dfs3(int u){
    v[u] = 1;
    dp[u] = scc[u];
    for(int i : mp2[u]){
        if(v[i] == 0)
            dp[u] = max(dp[u], scc[u] + dfs3(i));
        else if(v[i] == 2)
            dp[u] = max(dp[u], scc[u] + dp[i]);
    }
    v[u] = 2;
    return dp[u];    
}

int main() 
{ 
  int n,m,x = 0;
  cin>>n>>m;
  
  cost.assign(n+1,0);
  vis.assign(n+1,false);
  comp.assign(n+1,0);

  for(int i=1;i<=n;i++)
    cin>>cost[i];
  
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    mp[u].push_back(v);
    mpr[v].push_back(u);
  }  

  for(int i=1;i<=n;i++){
    if(!vis[i])
        dfs1(i);
  }

  vis.assign(n+1,false);
  reverse(used.begin(),used.end());  

  for(int i:used){
    if(!vis[i]){
        x++;
        dfs2(i,x);
    }
  }

  ll ans = 0;

  for(int i=1;i<=n;i++){
    for(int j:mp[i]){
        mp2[comp[i]].push_back(comp[j]);
    }
  }

  v.assign(x+1,0);

  for(int i=1;i<=x;i++){
    if(v[i] == 0)
        ans = max(ans,dfs3(i));
  }

  cout<<ans<<"\n";        
  return 0; 
}