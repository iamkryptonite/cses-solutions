#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;

int N = 2e5;

unordered_map<int,vector<int>> mp;
vector<vector<int>> dp;
vector<int> s;

int dfs(int u){
    
    dp[u][0] = 0;
    dp[u][1] = 0;
    s[u] = 1;

    for(int to:mp[u]){
        if(s[to] == 0){
            dp[u][0]+=dfs(to);
        }
    }

    for(int to:mp[u]){
        if(s[to] == 2)
            dp[u][1] = max(dp[u][1],dp[u][0] - dp[to][2] + 1 + dp[to][0]);        
    }


    s[u] = 2;
    dp[u][2] = max(dp[u][0],dp[u][1]);

    return dp[u][2]; 

}

int main(){
    dp.assign(N+1,vector<int>(3,-1));
    s.assign(N+1,0);

    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    int ans = dfs(1);
    cout<<ans<<"\n";

}