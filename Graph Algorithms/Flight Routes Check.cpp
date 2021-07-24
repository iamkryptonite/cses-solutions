// Use any strongly connected component algorithm(Kosaraju or Tarjans Algorithm)

#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map

u_map<int,vector<int>> mp,mpr;
vector<bool> vis;
vector<int> used;
int n,m;

void dfs1(int u){
  vis[u]=true;
  for(int to:mp[u])
    if(!vis[to])
      dfs1(to);
  used.push_back(u);
}

void dfs2(int u){
  vis[u] = true;
  for(int to:mpr[u])
    if(!vis[to])
      dfs2(to);
}

int main() 
{ 
  cin>>n>>m;
  vis.assign(n+1,false);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    mp[u].push_back(v);
    mpr[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs1(i);
  vis.assign(n+1,false);
  int root = used.back();
  used.pop_back();
  dfs2(root);
  for(int i:used){
    if(!vis[i]){
      cout<<"NO\n";
      cout<<i<<" "<<root<<"\n";
      return 0;
    }
  }
  cout<<"YES\n";


  return 0; 
}