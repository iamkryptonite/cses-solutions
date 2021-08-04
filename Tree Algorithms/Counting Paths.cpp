#include <bits/stdc++.h>
using namespace std;

vector<long int> d,lvl;
vector<vector<int>> up;
unordered_map<int,vector<int>> mp;
const int K = 20;

void dfs0(int u,int p,int l = 0){
  up[u][0] = p;
  lvl[u] = l;
  for(int i=1;i<K && up[u][i-1]!=-1;i++)
    up[u][i] = up[up[u][i-1]][i-1];

  for(auto to : mp[u]){
    if(to != p){
      dfs0(to , u , l + 1);
    }
  }
}

int lca(int a,int b){
  if(lvl[b] < lvl[a])
    swap(a,b);

  int d = lvl[b] - lvl[a];
  
  for(int i = 0 ; i < K ; i++){
    if(d & (1 << i))
      b = up[b][i];
  }
  
  if(a == b) return a;
  
  for(int i = K - 1 ; i >= 0 ; i--){
    if(up[a][i] != up[b][i])
      a = up[a][i],b = up[b][i];
  }
  
  return up[a][0];
}

int prefix(int u = 1,int p = -1){
  for(int to : mp[u]){
    if(to != p)
      d[u] += prefix(to,u);
  }
  return d[u];
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;
  cin >> n >> m;
  d.assign(n+1,0);
  lvl.assign(n+1,0);
  up.assign(n+1,vector<int>(K,-1));

  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    mp[u].push_back(v);
    mp[v].push_back(u);
  }

  dfs0(1,-1);

  while(m--){
    int u,v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
    int p = lca(u,v);
    int pp = up[p][0];
    d[p]--;
    if(pp!=-1)
      d[pp]--;
  }

  prefix(1);
  for(int i=1;i<=n;i++)
    cout<<d[i]<<" ";

}