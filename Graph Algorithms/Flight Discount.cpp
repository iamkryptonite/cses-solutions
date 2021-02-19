#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
u_map<int,vector<pair<int,int>>> mp;
vector<ull> d;
vector<ull> tmp;
void dijkstras(){
  set<pair<int,int>> q;
  q.insert({0,1});
  while(!q.empty()){
    int v=q.begin()->second;
    q.erase(q.begin());
    for(auto i:mp[v]){
      int to=i.first;
      ull w=i.second;
      if(to!=1 && ((tmp[v]+w<tmp[to] && d[v]+w==d[to] && tmp[v]+(w/2)==d[to]) || d[v]+w<d[to] || tmp[v]+(w/2)<d[to] || tmp[to]==0)){
        q.erase({d[to],to});
        d[to]=min(d[v]+w,tmp[v]+(w/2));
        tmp[to]=tmp[v]+w;
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
        int u,v,w;
        cin>>u>>v>>w;
        mp[u].push_back({v,w});
      }
      d.assign(n+1,0);
      tmp.assign(n+1,0);
      dijkstras();
      cout<<d[n]<<"\n";      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}