#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define u_map unordered_map
#define u_set unordered_set
#define vect vector
#define ull unsigned long long int
#define ll long long int
const int mod = 1000000007;
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
      int n,x;
      cin>>n>>x;
      vect<int> c(n);
      for(int i=0;i<n;i++)
        cin>>c[i];
      sort(c.begin(),c.end());
      vect<int> dp(x+1,0);
      dp[0]=1;
      for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
          if(c[j]>i)
            break;
          dp[i]+=dp[i-c[j]];
          dp[i]%=mod;
        }
      }
      cout<<dp[x]<<"\n";
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 