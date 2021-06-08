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
    cin>>n;
    if(n>=2 && n<=3){
      cout<<"NO SOLUTION";
      continue;
    }
    for(int i=2;i<=n;i+=2) 
      cout<<i<<" ";
    for(int i=1;i<=n;i+=2) 
      cout<<i<<" ";      
  }      
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
  return 0; 
}