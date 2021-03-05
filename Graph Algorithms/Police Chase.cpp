#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int

vector<u_set<int>> adj;

int bfs(int n,vect<int>& p){
  fill(p.begin(),p.end(),-1);
  p[1]=-1;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int next:adj[cur]){
      if(p[next]==-1){
        p[next]=cur;
        if(next==n)
          return 1;
        q.push(next);
      }
    }
  }
  return 0;
}

void max_flow(int n){
  int flow=0;
  vector<int> p(n+1);
  vector<pair<int,int>> edges;
  while(bfs(n,p)){
    flow++;
    int cur=n;
    while(cur!=1){
      int prev=p[cur];
      edges.push_back({prev,cur});
      adj[prev].erase(cur);
      adj[cur].erase(prev);
      cur=prev;
    }
  }
  cout<<flow<<"\n";
  for(pair<int,int> edge:edges){
    int u=edge.first;
    int v=edge.second;
    adj[u].insert(v);
    adj[v].insert(u);
    if(bfs(n,p)){
      cout<<u<<" "<<v<<"\n";
      adj[u].erase(v);
      adj[v].erase(u);
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
      adj.assign(n+1,{});
      for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
      }
      max_flow(n);
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}