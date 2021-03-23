#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
u_map<int,u_set<int>> mp;
vector<char> color;
int cycle_start;
bool dfs(int v) {
  color[v] = 1;
  for(int u : mp[v]) {
    if(color[u] == 0) {
      if(dfs(u))
        return true;
    }else if (color[u] == 1) {
      cycle_start = v;
      return true;
    }
  }
  color[v] = 2;
  return false;
}
bool is_Cyclic(int n){
  color.assign(n+1, 0);
  cycle_start = -1;
  for(int v = 0; v < n; v++) {
    if(color[v] == 0 && dfs(v))
      break;
  }
  if(cycle_start == -1)
    return false;
  return true;
}
void topo(int u,vect<bool>& vis){
  vis[u]=true;
  for(int i:mp[u])
    if(!vis[i])
      topo(i,vis);
  cout<<u<<" ";
}
int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
  #endif  
  int t=1;
  // cin>>t;
  while(t--) 
  {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){ 
      int u,v;
      cin>>u>>v;
      mp[v].insert(u);
    }
    if(!is_Cyclic(n)){
      vect<bool> vis(n+1,false);
      for(int i=1;i<=n;i++){
        if(!vis[i])
            topo(i,vis);
      }
    }else
    cout<<"IMPOSSIBLE"<<"\n";      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}