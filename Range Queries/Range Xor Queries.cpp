#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int

vect<ll> v;
vect<vect<ll>> st;
int n,q,k;

void query(int l,int r){
  ll x=0;
  for(int j=k;j>=0;j--){
    if((1<<j)<=r-l+1){
      x=x^st[l][j];
      l+=1<<j;
    }
  }
  cout<<x<<"\n";
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
    cin>>n>>q;
    k=log2(n)+1;
    v.assign(n,0);
    st.assign(n,vect<ll>(k+1));
    for(int i=0;i<n;i++) 
      cin>>v[i];
    for(int i=0;i<n;i++)
      st[i][0]=v[i];
    for(int j=1;j<=k;j++)
      for(int i=0;i+(1<<j)<=n;i++)
        st[i][j] = (st[i][j-1])^(st[i+(1<<j-1)][j-1]);
    
    int l,r;
    while(q--){
      cin>>l>>r;
      query(l-1,r-1);
    } 
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}