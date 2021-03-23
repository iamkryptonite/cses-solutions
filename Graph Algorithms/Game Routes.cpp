#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
u_map<int,u_set<int>> adj;
vect<bool> vis;
vect<ll> c;
const int mod=1000000007;
void dfs(int u,int n){
  vis[u]=true;
  for(int v:adj[u]){
    if(v==n || vis[v]){
      c[u]+=c[v];
      c[u]%=mod;
    }
    else{
      dfs(v,n);
      c[u]+=c[v];
      c[u]%=mod;
    }
  }
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
  while(t--) 
  {
    int n,m;
    cin>>n>>m;
    vis.assign(n+1,false);
    c.assign(n+1,0);
    c[n]=1;
    for(int i=0;i<m;i++){ 
      int u,v;
      cin>>u>>v;
      adj[u].insert(v);
    }
    dfs(1,n);
    c[1]%=mod;
    cout<<c[1]<<"\n";     
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}