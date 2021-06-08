#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int

u_map<int,vect<pair<int,ll>>> mp;
u_map<int,vector<ll>> dp;
vect<int> parent,isCycle;
vect<ll> score;
u_set<int> v;
int n,m;

bool loop = false;

void cycles(int u = 1){
  for(auto i:mp[u]){

    int to = i.first;
    ll x = i.second;
    
    if(v.find(to) == v.end()){
      v.insert(to);
      parent[to] = u;
      score[to] = score[u]+x;
      cycles(to);
      v.erase(to);
    }
    else if(score[u]+x-score[to]>0){
      int p = u;
      while(p != to){
        isCycle[p] = 1;
        p = parent[p];
      }
      isCycle[p] = 1;
    }
  }
}

vector<ll> dfs(int u=1){
  if(dp.find(u)!=dp.end()){
    return dp[u];
  }
  dp[u]={0,0};
  
  for(auto i:mp[u]){
    int to = i.first;
    ll x = i.second;
    if(v.find(to) == v.end()){
      v.insert(to);
      vect<ll> p = dfs(to);
      if(p[0]){
        if(dp[u][0] == 0)
          dp[u][1] = x+p[1];
        else
          dp[u][1] = max(dp[u][1],x+p[1]);
        dp[u][0] = 1;
      }
      v.erase(to);
    }    
  }
  if(isCycle[u] && dp[u][0])
    loop=true;
  return dp[u];
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
    cin>>n>>m;
    parent.assign(n+1,0);
    isCycle.assign(n+1,0);
    score.assign(n+1,0);
    int a,b;
    ll x;
    for(int i=0;i<m;i++){
      cin>>a>>b>>x;
      mp[a].push_back({b,x});
    }
    

    v.insert(1);
    cycles();

    v.clear();
    v.insert(1);
    dp[n]={1,0};
    dfs();

    if(isCycle[n])
      loop=true;

    if(loop)
      cout<<-1<<"\n";
    else
      cout<<dp[1][1]<<"\n";      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}