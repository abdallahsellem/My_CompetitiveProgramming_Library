vector<vector<int>> adj;
int precalc[(int)1e3][(int)1e3] ;
int vis[(int) 1e3 + 5];
int pathlen;
int path[(int) 1e3 + 5];
int n;
int get_path(int CurrNode, int EndNode, int len, int CurrMin) {
    vis[CurrNode] = 1;
    path[len] = CurrNode;
    if (EndNode == CurrNode) {
        pathlen = len + 1;
        return CurrMin;
    }
    int ret = 0;
    for (auto child:adj[CurrNode]) {
        if (!vis[child]&&precalc[CurrNode][child]>0) {
            ret = get_path(child, EndNode, len + 1, min(CurrMin, precalc[CurrNode][child]));
        }
        if (ret > 0) {
            break;
        }
    }
    return ret;
}

int max_flow(int src, int think) {
    int total = 0;
    while (true) {
        memset(vis,0,sizeof vis) ;
        pathlen =0 ;
        int newflow= get_path(src,think ,0,INT_MAX) ;
        if(!newflow)
        {
            break ;
        }

        for(int i=1 ;i<pathlen;i++)
        {
            int to =path[i] ;
            int from=path [i-1] ;
            precalc[from][to]-=newflow ;
            precalc[to][from]+=newflow ;
        }
        total +=newflow ;

    }
    return total ;
}