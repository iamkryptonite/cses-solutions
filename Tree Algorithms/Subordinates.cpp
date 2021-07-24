#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;
vector<int> ans;

int dfs(int u=1){
  int child = 0;
  for(int to:mp[u]){
    child+= 1 + dfs(to); 
  }
  ans[u] = child;
  return ans[u];
}

int main() 
{
  ios_base::sync_with_stdio(false);cin.tie(NULL); 
  int n;
  cin>>n;
  ans.assign(n+1,0);
  
  for(int i=2;i<=n;i++){
    int p;
    cin>>p;
    mp[p].push_back(i);
  }
  
  dfs();
  for(int i=1;i<=n;i++)
        cout<<ans[i]<<" "; 
  return 0; 
}