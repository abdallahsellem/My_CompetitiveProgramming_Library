vector<vector<int>>vec(1e5+5) ;
int vis[(int)1e5];
int id [(int)1e5+5] ;
int low[(int)1e5+5] ;
int arrc[(int)1e5+5] ;
int timer ;
int arc_point ;

void dfs(int node ,int par)
{
    int children =0 ;
    vis[node]=1 ;
    low[node]=id[node]=timer++ ;
    for(auto child :vec[node])
    {
        if(par==child)
            continue ;
        if(!vis[child])
        {
            dfs(child,node) ;
            low[node]=min(low[node],low[child]) ;
            if(id[node]<=low[child]&&par!=-1)
            {
               arrc[node]=1 ;
            }
            children++ ;
        }
        else
        {
            low[node]=min(low[node],id[child]) ;
        }


    }
    if(par==-1&&children>1)
    {
       arrc[node]=1 ;
    }

}