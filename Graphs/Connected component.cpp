vector<vector<int>>vec ;
int vis[sz] ;
int low [sz] ;
int id [sz] ;
int in_stack[sz] ;
stack<int>ss ;
int scc ;
int timer ;
vector<int>ans ;
vector<int>temp ;
void dfs(int node)
{
    vis[node]=1 ;
    //cout<<node<<" " ;
    in_stack[node]=1 ;
    ss.push(node) ;
    low[node]=id[node]=timer++ ;
    for(auto child:vec[node])
    {
        if(!vis[child])
        {
            dfs(child) ;
            if(in_stack[child]==1)
            {
                low[node]=min(low[node],low[child]) ;
            }
        }
        else if (vis[child]==1&&in_stack[child]==1)
        {
            low[node]=min(low[node],id[child]) ;
        }
    }
    if(low[node]==id[node])
    {
        int x ;
        scc++ ;
        while(1)
        {
            x =ss.top() ;
            temp.push_back(x) ;
           // cout<<x<<" "<<scc<<endl ;
            ss.pop() ;
            in_stack[x]=0 ;
            if(node==x)
            {
                break ;
            }
        }

    }
}
