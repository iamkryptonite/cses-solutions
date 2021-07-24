#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map

int n,m;
u_map<int,vector<int>> mp;
vector<int> p; //stores the parent 
int cyc_start = -1,cyc_end = -1; // start and end of cycle
vector<int> vs; //stores if visited or not

bool dfs(int u){
  vs[u] = 1;
  for(int to:mp[u]){
    if(to == u)
      continue;
    else if(vs[to]==0){
      p[to] = u;
      if(dfs(to))
        return true; 
    }else if(vs[to]==1){
      cyc_start = to;
      cyc_end = u;
      return true;
    }
  }
  vs[u] = 2;
  return false;
}


int main() 
{ 
  cin >> n >> m;
  p.assign(n + 1, 0);
  vs.assign(n + 1, 0);
  for(int i = 0;i < m; i++){
    int u,v;
    cin >> u >> v;
    mp[u].push_back(v);
  }
  for(int i = 1;i <= n; i++){
    if(vs[i] == 0 && dfs(i))
      break;
  }
  if(cyc_start == -1)
    cout<<"IMPOSSIBLE\n";
  else{
    vector<int> ans;
    ans.push_back(cyc_start);
    while(cyc_end != cyc_start){
      ans.push_back(cyc_end);
      cyc_end = p[cyc_end];
    }
    ans.push_back(cyc_start);
    cout << ans.size() << "\n";
    reverse(ans.begin(),ans.end());
    for(int i : ans)
      cout << i << " ";
  }  
  return 0; 
}