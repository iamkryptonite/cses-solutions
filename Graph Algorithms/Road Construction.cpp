// MST using Krushkal and DSU
#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int u,v;
};

int maxcomp = 1; //max size of component
vector<int> p; //parent array
vector<int> s; //size of component

int find(int v){
  if(p[v]==v)
    return v;
  return p[v] = find(p[v]);
}

void union_find(int a,int b){
  a = find(a);
  b = find(b);
  if(a!=b){
    if(s[a]<s[b])
      swap(a,b);
    p[b] = a;
    s[a]+=s[b];
    maxcomp = max(s[a],maxcomp);
  }
} 

int main() 
{ 
  int n,m;
  cin >> n >> m;

  Edge e[m];
  p.assign(n+1 , 0);
  s.assign(n+1 , 1);
  iota(p.begin(),p.end(),0);
  
  for(int i = 0;i < m ; i++)
    cin >> e[i].u >> e[i].v;

  for(int i = 0; i < m; i++){
    if(find(e[i].u)!=find(e[i].v)){
      n--;
      union_find(e[i].u,e[i].v);
    }
    cout<<n<<" "<<maxcomp<<"\n"; 
  }
  return 0; 
}