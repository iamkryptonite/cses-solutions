#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
u_map<int,vector<int>> mp;
bool is_bipartite=true;
vector<int> s;
void bipartite(int n){
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(s[i]==-1){
      s[i]=1;
      q.push(i);
      while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u:mp[v]){
          if(s[u]==-1 && s[v]==1){
            s[u]=2;
            q.push(u);
          }
          else if(s[u]==-1 && s[v]==2){
            s[u]=1;
            q.push(u);
          }
          else
            is_bipartite &= (s[u]!=s[v]);
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
      s.assign(n+1,-1);
      bipartite(n);
      if(is_bipartite){
        for(int i=1;i<=n;i++)
          cout<<s[i]<<" ";
        cout<<"\n";
      }else
        cout<<"IMPOSSIBLE"<<"\n";      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}