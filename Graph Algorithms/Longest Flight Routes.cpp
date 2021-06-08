#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int

vect<bool> vis; // store if visited or not
vect<int> len; // store distance of node from last node n 
vect<int> child; // store child of node 
u_map<int,vect<int>> adj; // adjacency list
int n,m; 


void dfs(int u = 1){
  vis[u] = true;
  for(int v : adj[u]){
    if(u==1 || v==1)
    if(v != n && !vis[v])
      dfs(v);
    if(1 + len[v] > len[u] && child[v] != -1){
      len[u] = 1 + len[v];
      child[u] = v;
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
  
  cin>>n>>m;
  vis.assign(n+1,false);
  len.assign(n+1,0);
  child.assign(n+1,-1);
  child[n] = 0;

  for(int i = 0;i < n; i++){ 
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }

  dfs();
  cout<<len[1];

  if(child[1] == -1){
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
  }

  cout<<1 + len[1]<<"\n";
  int i = 1;
  while(i != 0){
    cout<<i<<" ";
    i = child[i];
  }     
        
  return 0; 
}