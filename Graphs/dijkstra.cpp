#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> adj[N];
long long dis[N];
int par[N];

void dijkstra(int src) {
    memset(dis, '?', sizeof dis);
    memset(par, -1, sizeof par);
    dis[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (pq.size()) {
        long long d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dis[u] != d) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, c = adj[u][i].second;
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                par[v] = u;
                pq.push({-(dis[u] + c), v});
            }
        }
    }
}

void go(int u) {
    if (u == -1) return;
    go(par[u]);
    printf("%d ", u + 1);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);


    int n, m, src, dest;
    scanf("%d%d", &n, &m);

    src = 0, dest = n - 1;
    for (int i = 0; i < n; ++i) adj[i].clear();

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u, --v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dijkstra(src);

    if (dis[dest] == dis[n]) puts("-1");
    else go(n - 1);


    return 0;
}