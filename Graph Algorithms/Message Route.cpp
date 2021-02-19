#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
u_map<int,vect<int>> mp;
vector<int> d;
vector<int> p;
void path(int v){
  if(v==0) 
    return;
  path(p[v]);
  cout<<v<<" ";
}
void dijkstras(){
  set<pair<int,int>> q;
  q.insert({1,1});
  while(!q.empty()){
    int v=q.begin()->second;
    q.erase(q.begin());
    for(int to:mp[v]){
      if(d[v]+1<d[to]){
        q.erase({d[to],to});
        d[to]=d[v]+1;
        p[to]=v;
        q.insert({d[to],to});
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
      d.assign(n+1,2*n);
      p.assign(n+1,0);
      d[1]=1;
      dijkstras();
      if(d[n]!=2*n){
        cout<<d[n]<<"\n";
        path(n);
      }else
        cout<<"IMPOSSIBLE"<<"\n";   
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}