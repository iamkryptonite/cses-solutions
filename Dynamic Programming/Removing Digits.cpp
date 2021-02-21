#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
int maxD(ll n){
  int d=0;
  while(n){
    if(d<n%10)
      d=n%10;
    n/=10;
  }
  return d;
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
      int n;
      cin>>n;
      vector<ull> dp(n+1);
      dp[0]=0;
      int x=0;
      for(int i=1;i<=n;i++){
        int d=maxD(i);
        dp[i]=1+dp[i-d];
      }
      cout<<dp[n]<<"\n";      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}