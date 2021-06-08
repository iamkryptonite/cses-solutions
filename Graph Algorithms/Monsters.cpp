#include <bits/stdc++.h>
#include <cstdio>
#include <iostream> 
using namespace std;
#define vect vector

vect<vect<char>> v;
vect<vect<int>> M,d,p;
int n,m,ans = -1,a = -1,b = -1;
string path;

int  dx[4] = { 1 ,-1 , 0 , 0 };
int  dy[4] = { 0 , 0 , 1 ,-1 };
char dr[4] = {'D','U','R','L'};

bool check(int x,int y,int i,int l){
  if(x + dx[i] < 0 || x+dx[i] >= n ) return false;
  if(y + dy[i] < 0 || y+dy[i] >= m ) return false;
  if(v[x + dx[i]][y + dy[i]] == '#') return false;
  if(l+1 >= d[x + dx[i]][y + dy[i]]) return false;
  if( p[x + dx[i]][y + dy[i]] == 1 ) return false;
  return true;
}

void computeDistance(int x,int y,int l=0){
  d[x][y] = min(d[x][y],l);
  for(int i = 0;i < 4;i++){
    if(check(x,y,i,l)){
      p[x + dx[i]][y + dy[i]] = 1;
      computeDistance(x+dx[i],y+dy[i],l+1);
      p[x + dx[i]][y + dy[i]] = 0;    
    }
  }
}

void isPossible(int x,int y,int l=0,string s=""){
  if(x==0 || x==n-1 || y==0 || y==m-1){
    ans=l;
    path=s;
    return;
  }
  for(int i=0;i<4;i++){
    if(check(x,y,i,l) && ans==-1){
      p[x + dx[i]][y + dy[i]] = 1;
      isPossible(x+dx[i],y+dy[i],l+1,s+dr[i]);
      p[x + dx[i]][y + dy[i]] = 0;    
    }
  }
}

int main() 
{ 
  ios_base::sync_with_stdio(false);cin.tie(NULL);   
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("error.txt", "w", stderr); 
  freopen("output.txt", "w", stdout); 
  #endif
  
  cin>>n>>m;

  v.assign(n,vect<char>(m));  
  d.assign(n,vect<int>(m,INT_MAX));
  p.assign(n,vect<int>(m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>v[i][j];
      if(v[i][j]=='M'){
        M.push_back({i,j});
        d[i][j]=0;
      }
      if(v[i][j]=='A'){
        a=i;
        b=j;
      }
    }
  }

  if(a==-1 && b==-1){
    cout<<"NO"<<"\n";
    return 0;
  }

  for(auto i : M){
    p[i[0]][i[1]] = 1;
    computeDistance(i[0],i[1]);
    p[i[0]][i[1]] = 0;
  }

  p.assign(n,vect<int>(m,0));

  p[a][b]=1;
  isPossible(a,b);
  
  if(ans!=-1){
    cout<<"YES"<<"\n";
    cout<<ans<<"\n";
    cout<<path<<"\n";
  }else
    cout<<"NO"<<"\n";
    
  return 0; 
}