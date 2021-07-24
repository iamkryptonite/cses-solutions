#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;

int n,m;
vector<int> t,v;

void build(int tl,int tr,int i){
    if(tl==tr){
        t[i] = v[tl];
        // cout<<t[i]<<" ";
    }
    else{
        int tm = (tl+tr)/2;
        build(tl,tm,2*i);
        build(tm+1,tr,2*i+1);
        t[i] = max(t[2*i],t[2*i+1]); 
    }
}

int findIndex(int tl,int tr,int target,int i){
    if(tl > tr) return -1;
    if(t[i] < target) return -1;
    if(tl == tr){
        if(t[i] >= target){
            return tl;
        }
        return -1;
    }
    int tm = (tl+tr)/2;
    int idx = findIndex(tl,tm,target,2*i);
    if(idx == -1)
        idx = findIndex(tm+1,tr,target,2*i+1);
    return idx;
}

void update(int tl,int tr,int i,int pos,int g){
    if(tl>tr) return;
    if(tl==tr)
        t[i]-=g;
    else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(tl,tm,2*i,pos,g);
        else
            update(tm+1,tr,2*i+1,pos,g);
        t[i] = max(t[2*i],t[2*i+1]);
    }
}

int main(){
    cin>>n>>m;
    t.assign(4*n,0); 
    v.assign(n,0);   
    for(int i=0;i<n;i++) cin>>v[i];
    
    build(0,n-1,1);
    
    while(m--){
        int g;
        cin>>g;
        int i = findIndex(0,n-1,g,1);
        cout<<i+1<<" ";
        if(i!=-1)
            update(0,n-1,1,i,g);        
    }
}