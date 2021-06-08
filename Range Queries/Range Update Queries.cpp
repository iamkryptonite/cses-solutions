#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
vect<ll> v,bit;
void build(int i,int tl,int tr){
  if(tl==tr){
    bit[i]=v[tl];
  }
  else{
    int tm = (tl+tr)/2;
    build(i*2,tl,tm);
    build(i*2+1,tm+1,tr);
  }
}
void range_update(int i,int tl,int tr,int l,int r,ll val){
  if(l > r)
    return;
  if(l == tl && r == tr) {
    bit[i] += val;
  }else{
    int tm = (tl + tr) / 2;
    range_update(i*2, tl, tm, l, min(r, tm), val);
    range_update(i*2+1, tm+1, tr, max(l, tm+1), r, val);
  }  
}
ll query(int i,int tl,int tr,int pos){
  if(tl==tr)
    return bit[i];
  else{
    int tm = (tl+tr)/2;
    if(pos<=tm)
      return bit[i] + query(i*2,tl,tm,pos);
    else
      return bit[i] + query(i*2+1,tm+1,tr,pos);
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
    int n,q;
    cin>>n>>q;
    v.assign(n,0);
    bit.assign(4*n,0);
    for(int i=0;i<n;i++) 
      cin>>v[i];
    build(1,0,n-1);
    int c,x,y;
    ll z;
    while(q--){
      cin>>c;
      if(c==1){
        cin>>x>>y>>z;
        range_update(1,0,n-1,x-1,y-1,z);
      }
      else{
        cin>>x;
        cout<<query(1,0,n-1,x-1)<<"\n";
      }
    }      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}