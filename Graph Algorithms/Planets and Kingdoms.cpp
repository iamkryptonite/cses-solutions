#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map

vector<int> used,comp;
vector<bool> vis;
u_map<int,vector<int>> mp,mpr;

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
  comp[u] = p;
  
  for(int i:mpr[u])
    if(!vis[i])
      dfs2(i,p);
}

int main() 
{ 
  int n,m,ans = 0;
  cin>>n>>m;
  
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    mp[u].push_back(v);
    mpr[v].push_back(u);
  }

  vis.assign(n+1,false);
  comp.assign(n+1,-1);
  
  for(int i=1;i<=n;i++){
    if(!vis[i])
      dfs1(i);
  }
  
  vis.assign(n+1,false);
  reverse(used.begin(),used.end());

  for(int i:used){
    if(!vis[i]){
      ans++;
      dfs2(i,ans);
    }
  }

  cout<<ans<<"\n";
  for(int i=1;i<=n;i++)
    cout<<comp[i]<<" ";
  cout<<"\n";
  return 0; 
}