#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define ll long long int
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
      int n,m,q;
      cin>>n>>m>>q;
      vector<vector<ll>> d(n+1,vector<ll>(n+1,-1));
      for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        if(d[u][v]==-1){
          d[u][v]=w;
          d[v][u]=w;
        }else{
          d[u][v]=min(d[u][v],w);
          d[v][u]=d[u][v];
        }
      }
      for(int i=1;i<=n;i++)
        d[i][i]=0;
      for(int k=1;k<=n;++k) {
        for(int i=1;i<=n;++i) {
          for(int j=1;j<=n;++j) {
            if(d[i][j]== -1 && d[i][k]!=-1 && d[k][j]!=-1)
              d[i][j] = d[i][k] + d[k][j];
            else if(d[i][k]!=-1 && d[k][j]!=-1)
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
          }
        }
      }      
      while(q--){
        int u,v;
        cin>>u>>v;
        cout<<d[u][v]<<"\n";
      }      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}