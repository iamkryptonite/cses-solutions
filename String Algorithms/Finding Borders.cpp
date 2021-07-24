#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  string s;
  cin>>s;
  int n = s.length();
  vector<int> z(n,0);
  vector<int> ans;
  for(int i=1,l=0,r=0;i<n;i++){
    if(i<=r)
      z[i] = min( z[i-l], r - i + 1);
    while(i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;      
  }
  for(int i = 0; i<n ; i++){
    if(i + z[i] == n)
      ans.push_back(z[i]);
  }
  sort(ans.begin(),ans.end());
  for(int i:ans)
    cout<<i<<" ";
  cout<<"\n";
  return 0; 
}