vector<vector<pair<int,int>>> adj;
int vis[(int) 1e5 + 5];
int par[(int) 1e5 + 5];
int cost =0 ;
void MST(int node) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});
    while (!pq.empty()) {
        auto currNode = pq.top();
        pq.pop();
        if(vis[currNode.second])
        {
            continue;
        }
        vis[currNode.second] = 1;
        cost +=currNode.first*-1 ;
       // cout<<currNode.second<<endl ;
        for (auto child :adj[currNode.second]) {
            if (!vis[child.first]) {
                pq.push({-1*child.second,child.first}) ;
                par[child.first]=currNode.second ;
                cout<<child.first<<" "<<currNode.second <<endl ;
            }
        }
    }
}

int32_t main() {
    iso;
   int n ,m  ;
   cin>> n>>m;
   adj.resize(n+1) ;
   for(int i=0 ;i<m ;i++)
   {
       int u ,v ,c ;
       cin>> u>>v>>c ;
       adj[u].pb({v,c}) ;
       adj[v].pb({u,c}) ;
   }
   MST(1) ;
   int pt =1 ;
   cout<<cost<<endl ;
   
}