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
    int n;
    long long int ans=0;
    cin>>n;
    vect<int> v(n);
    for(int i=0;i<n;i++) 
      cin>>v[i];
    for(int i=1;i<n;i++){
      if(v[i]<v[i-1]){
        ans+=v[i-1]-v[i];
        v[i]=v[i-1];
      }
    }
    cout<<ans<<"\n";      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}