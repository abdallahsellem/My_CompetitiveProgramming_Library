/*********************/
//Hard work beats talent when talent doesn’t work hard
// 1% talent but 99% belive and hard work
/*********************/
#include <iostream>

using namespace std;

#include<bits/stdc++.h>

#define int long long
#define ll long long
#define wh while (t--)
#define pb push_back
#define  popcount __builtin_popcountll
#define beg begin()
#define endi end()
#define f first
#define sec second
#define endl '\n'
#define mem(arr) memset(arr,0,sizeof arr)
#define iso ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//freopen ("text_file.txt", "w", stdout);
ll gcd(ll x, ll y) {
    return (y == 0 ? x : gcd(y, x % y));
}

ll lcm(ll x, ll y) {
    return (x / gcd(x, y)) * y;
}
const int sz =2e5+5 ;
vector<vector<int>>vec ;
int vis[sz] ;
int in_stack[sz] ;
stack<int>ss ;
vector<int>cost ;
int temp ;
void dfs(int node)
{
    vis[node]=1 ;
    in_stack[node]=1 ;
    ss.push(node) ;
    for(auto child:vec[node])
    {
        if(!vis[child]) {
            dfs(child);
        }
        else if(vis[child]==true&&in_stack[child])
        {
          //  cout<<child<<endl ;
            while((!ss.empty())&&ss.top()!=child)
            {
                in_stack[ss.top()]=0 ;
                temp =min(cost[ss.top()],temp) ;
                ss.pop() ;
            }
            if((!ss.empty())&&ss.top()==child)
            {
                temp=min(cost[child],temp) ;
                in_stack[child]=0 ;
                ss.pop() ;
            }

        }
    }
}
int32_t main() {
    int n  ;
    cin>> n ;
    vec.resize(n+1) ;
    cost.resize(n+1) ;
    int arr[n+1] ;
    for(int i=1 ;i<=n ;i++)
    {
        cin>> cost[i] ;
    }
    for(int i=1 ;i<=n ;i++)
    {
        cin>> arr[i] ;
        vec[i].pb(arr[i]) ;
    }
    int ans =0 ;

    for(int i=1 ;i<=n;i++)
    {
         temp =1e9 ;
         if(!vis[i])
        dfs(i) ;
        //cout<<"******************"<<endl ;
        while(!ss.empty())
        {
            in_stack[ss.top()]=0 ;
            ss.pop() ;
        }
        if(temp!=1e9)
        {
            ans+=temp ;
        }
    }
    cout<<ans<<endl ;


}
