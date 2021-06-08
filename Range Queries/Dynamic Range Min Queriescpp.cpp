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
vect<ull> bit;

void build(int i,int tl,int tr){
  if(tl==tr)
    bit[i] = v[tl];
  else{
    int tm = (tl+tr)/2;
    build(i*2,tl,tm);
    build(i*2+1,tm+1,tr);
    bit[i] = min(bit[i*2],bit[i*2+1]);
  }
}

void update(int i,int tl,int tr,int pos,int val){
  if(tl == tr)
    bit[i] = val;
  else{
    int tm = (tl + tr)/2;
    if(pos <= tm)
      update(i*2, tl, tm, pos, val);
    else
      update(i*2+1, tm+1, tr, pos, val);
    bit[i] = min(bit[i*2],bit[i*2+1]);
  }
}

ull query(int i,int tl,int tr,int l,int r){
  if(l>r) 
    return 1e9+1;
  if(tl==l && tr==r)
    return bit[i];
  
  int tm=(tl+tr)/2;

  return min(query(i*2,tl,tm,l,min(r,tm)),
    query(i*2+1,tm+1,tr,max(tm+1,l),r));
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
    bit.assign(4*n,1e9+1);
    for(int i=0;i<n;i++) 
      cin>>v[i];    
    build(1,0,n-1);
    int c,a,b;
    
    while(q--){
      cin>>c>>a>>b;
      if(c==1)
        update(1,0,n-1,a-1,b);
      else
        cout<<query(1,0,n-1,a-1,b-1)<<"\n";
    }      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}