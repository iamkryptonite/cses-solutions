#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
u_map<int,vector<int>> mp;
u_set<int> vis;
vector<int> l;
vector<int> p;
int start_vertex=-1;
int size=0;
void dfs(int n){
  for(int i=1;i<=n;i++){
    if(vis.find(i)==vis.end()){
      vis.insert(i);
      stack<int> q;
      l[i]=1;
      q.push(i);
      while(!q.empty()){
        int v=q.top();
        q.pop();
        vis.insert(v);
        for(int u:mp[v]){
          if(vis.find(u)==vis.end()){
            p[u]=v;
            l[u]=l[v]+1;
            q.push(u);
          }else if(l[v]-l[u]>=2){ 
            p[u]=v;
            start_vertex=u;
            size=l[v]-l[u]+2;
            return;
          }
        }
      }
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
      for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
      }
      l.assign(n+1,0);
      p.assign(n+1,-1);
      dfs(n);
      if(start_vertex==-1)
        cout<<"IMPOSSIBLE"<<"\n";
      else{
        cout<<size<<"\n";
        int i=start_vertex;
        do{
          cout<<i<<" ";
          i=p[i];
        }while(i!=start_vertex);
        cout<<start_vertex<<"\n";
      }
      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}