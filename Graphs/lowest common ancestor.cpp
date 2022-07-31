#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int LCA[(int) 2e5 + 5][33];
vector<vector<int>> adj;
int n;
int vis[(int) 2e5 + 5];
int level[(int) 2e5 + 5];
void dfs(int node, int par) {
    LCA[node][0] = par;
    for (auto child:adj[node]) {
        if (par != child) {
            dfs(child, node);
        }
    }
}
void bfs(int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    while (!q.empty()) {
        auto pt = q.front();
        q.pop();
        level[pt.first] = pt.second;
        // cout<<pt.first<<" "<<pt.second<<endl ;
        vis[pt.first] = 1;
        for (auto child:adj[pt.first]) {
            if (!vis[child]) {
                q.push({child, pt.second + 1});
            }
        }
    }
}
void init() {
    memset(LCA, -1, sizeof LCA);
    dfs(1, -1);
    memset(vis, 0, sizeof vis);
    bfs(1);
    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= n; j++) {
            if (LCA[j][i - 1] != -1) {
                int par = LCA[j][i- 1];
                LCA[j][i] = LCA[par][i- 1];
            }
        }
    }
}
int get_lca(int u, int v) {
    if (level[u] < level[v]) {
        swap(u, v);
    }
    int d = level[u] - level[v];
    while (d) {
        int i = log2(d);
        u = LCA[u][i];
        d -= (1 << i);
    }
    if (u == v) {
        return u;
    }
    for (int i = 32; i >= 0; i--) {
        if (LCA[u][i] != -1 && (LCA[u][i] != LCA[v][i])) {
            u = LCA[u][i];
            v = LCA[v][i];
        }
    }
    return LCA[u][0];
}
int main() {
    cin >> n;
    adj.resize(n + 2);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();
}
