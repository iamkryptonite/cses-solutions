#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
const ll INF = 1e9+1;
vector<vector<ll>> capacity;
vector<u_set<int>> adj;
ll bfs(int n,vect<int>& parent){
  fill(parent.begin(),parent.end(),-1);
  parent[1]=-2;
  queue<pair<int,ll>> q;
  q.push({1,INF});
  while(!q.empty()){
    int cur=q.front().first;
    ll flow=q.front().second;
    q.pop();
    for(int next:adj[cur]){
      if(parent[next]==-1 && capacity[cur][next]){
        parent[next]=cur;
        ll new_flow=min(flow,capacity[cur][next]);
        if(next==n)
          return new_flow;
        q.push({next,new_flow});
      }
    }
  }
  return 0;
}
void max_flow(int n){
  ull flow=0;
  vector<int> parent(n+1);
  ll new_flow;
  while(new_flow=bfs(n,parent)){
    flow+=new_flow;
    int cur=n;
    while(cur!=1){
      int prev=parent[cur];
      capacity[prev][cur]-=new_flow;
      capacity[cur][prev]+=new_flow;
      cur=prev;
    }
  }
  cout<<flow<<"\n";
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
      ll n,m;
      cin>>n>>m;
      adj.assign(n+1,{});
      capacity.assign(n+1,vector<ll>(n+1,0));
      for(int i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].insert(v);
        adj[v].insert(u);
        capacity[u][v]+=c;
      }
      max_flow(n);
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}