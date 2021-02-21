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
      string s;
      cin>>s;
      int l=s.length(),ans=0,ln=1;
      for(int i=0;i<l-1;i++){
        if(s[i]==s[i+1])
          ln++;
        else{
          ans=max(ans,ln);
          ln=1;
        }
      }
      ans=max(ans,ln);
      cout<<ans<<"\n";
      
   }      
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 