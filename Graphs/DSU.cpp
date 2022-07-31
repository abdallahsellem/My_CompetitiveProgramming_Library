struct dsu {
    int par[N], rank[N];

    void init() {
        iota(par, par + N, 0);
        memset(rank, 0, sizeof rank);
    }

    int root(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = root(par[u]);
    }

    void make_set(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) {
            return;
        }
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        par[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }

} DSU;