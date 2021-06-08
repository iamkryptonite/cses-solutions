#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
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
    int n,q;
    cin>>n>>q;
    vect<ll> v(n);
    for(int i=0;i<n;i++) 
      cin>>v[i];
    ll k = log2(n)+1;
    vect<vect<ll>> st(n,vect<ll>(k+1));

    for(int i=0;i<n;i++)
      st[i][0]=v[i];

    for(int j=1;j<=k;j++){
      for(int i=0;i+(1<<j)<=n;i++)
        st[i][j] = min(st[i][j-1],st[i + (1 << (j-1))][j-1]);
    }
    int l,r;
    while(q--){
      cin>>l>>r;
      l--;
      r--;
      int j = log2(r-l+1);
      cout<<min(st[l][j],st[r-(1<<j)+1][j])<<"\n";
    }
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}