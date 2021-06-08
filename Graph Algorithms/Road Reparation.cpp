//Minimum spanning tree using Krushkals algo and DSU
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Edge{
  int u,v;
  ll w;
  bool operator<(Edge const& e){
    return w < e.w;
  }
};

vector<int> p; //parent
vector<int> r; //rank

int find(int v){
  if(p[v] == v)
    return v;
  return p[v] = find(p[v]);
}

void union_find(int a,int b){
  a = find(a);
  b = find(b);
  if(a != b){
    if(r[a] < r[b])
      swap(a,b);
    p[b] = a;
    if(r[a] == r[b])
      r[a]++;
  }
}

int main() 
{ 
  int n,m;
  ll cost  = 0;
  cin >> n >> m;

  p.assign(n+1,0);
  r.assign(n+1,0);
  iota(p.begin(),p.end(),0);

  Edge e[m];
  for(int i = 0;i < m; i++){
    cin >> e[i].u >> e[i].v >> e[i].w;
  }

  sort(e,e + m); 

  for(int i = 0;i < m; i++){
    if(find(e[i].u) != find(e[i].v)){
      cost += e[i].w;
      n--;
      union_find(e[i].u , e[i].v);
    }
  }
  if(n>1)
    cout<<"IMPOSSIBLE\n";
  else
    cout<<cost<<"\n"; 
  return 0; 
}