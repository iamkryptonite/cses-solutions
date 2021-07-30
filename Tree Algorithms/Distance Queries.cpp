#include <bits/stdc++.h>
using namespace std;

vector<int> eu;
vector<int> first;
vector<vector<int>> st;
map<int,vector<int>> mp;
vector<int> h;
int n,q,l;

void dfs(int u = 1,int p = -1,int ht = 0){
    h[u] = ht;

    eu.push_back(u);
    first[u] = eu.size()-1;
    h[u] = ht;
    
    for(int to:mp[u]){
        if(to==p) continue;
        dfs(to,u,ht+1);
        eu.push_back(u);
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> q;

    l = ceil(log2(n));
    first.assign(n+1,0);
    h.assign(n+1,0);

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs();

    int N = eu.size();
    int k = log2(N);
    st.assign(N,vector<int>(k+1,0));

    for(int i=0;i<N;i++)
        st[i][0] = h[eu[i]];

    for(int j=1;j<=k;j++)
        for(int i=0;i+(1<<j)<=N;i++)
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        
    

    while(q--){
        int u,v;
        cin >> u >> v;
        int l = first[u];
        int r = first[v];
        if(r<l)
            swap(l,r);
        int j = log2(r-l+1);
        int lca = min(st[l][j],st[r-(1<<j)+1][j]);
        int ans = h[u] + h[v] - 2*lca;        
        cout<<ans<<"\n";
    }
}