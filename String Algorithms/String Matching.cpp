#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
  string n,m;
  cin >> n >> m;
  string s = m + "$" + n;
  int ans = 0, l = m.length(),len = s.length();

  vector<int> z(s.length(),0);
  for(int i = 1,l = 0,r = 0; i<len ; i++){
    if(i <= r)
      z[i] = min(z[i-l], r-i+1);
    while(i + z[i] < len && s[z[i]] == s[i + z[i]])
      ++z[i];
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  for(int i : z)
    if(i == l)
      ans++;
  cout<<ans<<"\n";
  return 0; 
}