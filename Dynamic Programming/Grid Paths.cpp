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
      int n;
      cin>>n;
      vect<vect<char>> v(n,vect<char>(n));
      vect<vect<ll>> dp(n,vect<ll>(n,0));
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          cin>>v[i][j];
      queue<pair<int,int>> q;
      q.push({n-1,n-1});
      while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        if(x==n-1 && y==n-1 && v[x][y]=='.')
          dp[x][y]=1;
        else if(dp[x][y]==-1 && v[x][y]!='*'){
          dp[x][y]=0;
          if(x+1<n)
            dp[x][y]+=dp[x+1][y]%mod;
          if(y+1<n)
            dp[x][y]+=dp[x][y+1]%mod;
        }else if(v[x][y]=='*')
          dp[x][y]=0;
        q.pop();        
        if(x-1>=0 && dp[x-1][y]!=-1){
          q.push({x-1,y});
          dp[x-1][y]=-1;
        }
        if(y-1>=0 && dp[x][y-1]!=-1){
          q.push({x,y-1});
          dp[x][y-1]=-1;
        }
 
      }
      cout<<dp[0][0]%mod<<"\n";      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}