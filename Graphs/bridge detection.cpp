#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 int n ,m;
 vector<vector<int>>vec(1e5+5) ;
 int vis[(int)1e5+5] ;
 int in[(int)1e5+5] ;
 int low[(int)1e5+5] ;
 int cnt =0 ;
 bool flag=true ;
 vector<pair<int,int>>ans ;
 void dfs(int node , int par)
 {
    vis[node]=1 ;
    low[node]=in[node]=cnt++ ;
    for(auto child :vec[node])
    {
        if(child==par)
        {
            continue ;
        }
       if(!vis[child])
       {

           dfs(child,node) ;
           if(low[child]>in[node])
           {
               cout<<"there is a bridge"<<endl ;
               flag=false ;
               return ;
           }
           low[node]=min(low[child],low[node]) ;


       }
       else
       {
          low[node]=min(low[node],in[child]) ;


       }
    }
 }
