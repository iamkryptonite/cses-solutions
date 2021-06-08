//--------------Using Bellman Ford algorithm-----------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//struct to store the weighted directed edges
struct Edge{
  int u, v;
  ll w;
};

int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
  #endif  
  int n,m;
  cin>>n>>m;

  Edge edges[m];
  ll d[m] ;
  int p[m] = {-1};

  for(int i = 0;i < m; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;

  int x = -1;

  //-------------Bellman ford--------------------
  for(int i = 1;i <= n; i++){
    x = -1;
    for(auto j : edges){
      if(d[j.u] + j.w < d[j.v]){
        d[j.v] = d[j.u] + j.w;
        p[j.v] = j.u;
        x = j.v;
      }
    }
  }
  //----------------------------------------------

  if(x == -1) // no modification on last iteration,then there are no negative cycles 
    cout<<"NO\n";
  else{
    cout<<"YES\n";

    for(int i = 0; i < n; i++) 
      x = p[x];

    vector<int> cyc;
    for(int v=x;;v=p[v]){
      cyc.push_back(v);
      if(v==x && cyc.size()>1)
        break;
    }

    reverse(cyc.begin(),cyc.end());
    for(int i:cyc)
      cout<<i<<" ";
    cout<<"\n";
  } 
  return 0; 
}