#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

// LCA using doubling
class LCA_DBL {
    using IL = pair<int,long long>;
    bool done = false;
    int n, k = 0;
    vector<vector<int>> p;
    vector<vector<IL>> from;
    vector<int> depth;
    vector<long long> dist;
    int climb(int v, int x) {
        for(int i=0; i<=k; ++i) if(x>>i&1) v = p[i][v];
        return v;
    }
public:
    LCA_DBL(int n): n(n), from(n), depth(n), dist(n) {
        while((1LL<<k)<n) ++k;
        p.resize(k+1, vector<int>(n));
    }
    void add_edge(int a, int b, long long w=1) {
        from[a].emplace_back(b, w);
        from[b].emplace_back(a, w);
    }
    void build(int rv=0) {
        if(done) return;
        done = true;
        auto dfs=[&](auto f, int v, int dep=0, long long d=0, int pv=-1) -> void {
            if(pv==-1) p[0][v] = v;
            else p[0][v] = pv;
            dist[v] = d;
            depth[v] = dep;
            for(auto [nv,w]: from[v]) if(nv!=pv) f(f, nv, dep+1, d+w, v);
        };
        dfs(dfs, rv);
        for(int j=0; j<k; ++j) for(int i=0; i<n; ++i) p[j+1][i] = p[j][p[j][i]];
    }
    int lca(int a, int b) {
        build();
        if(depth[a]>depth[b]) swap(a,b);
        b = climb(b, depth[b]-depth[a]);
        if(a==b) return a;
        for(int i=k; i>=0; --i) {
            if(p[i][a]==p[i][b]) continue;
            a = p[i][a], b = p[i][b];
        }
        return p[0][a];
    }
    long long get_dist(int a, int b) {
        int c = lca(a, b);
        return dist[a]+dist[b]-2*dist[c];
    }
};

using S = int;
S op(S a, S b) {return min(a, b);}
S e() {return 1001001001;}

struct LCA {
    int n, idx=0;
    vector<int> et, in;
    vector<long long> depth;
    struct Edge {
        int to, id;
        long long w;
    };
    vector<vector<Edge>> from;
    segtree<S,op,e> rmq;
    LCA(long long n): n(n) {
        from.resize(n);
        in.resize(n);
        depth.resize(n);
    }
    void add_edge(int a, int b, long long w=1) {
        from[a].emplace_back(b, w, idx);
        from[b].emplace_back(a, w, idx);
        ++idx;
    };
    void euler_tour(int v=0) {
        dfs(v);
        rmq = segtree<S,op,e>(et.size());
        for(int i=0; i<(int)et.size(); ++i) {
            rmq.set(i, in[et[i]]);
        }
    }
    void dfs(int v, long long d=0, int p=-1) {
        in[v] = et.size();
        depth[v] = d;
        et.push_back(v);
        for(auto [nv, w, id]: from[v]) if (nv != p) {
            dfs(nv, d+w, v);
            et.push_back(v);
        }
    }
    int lca(int a, int b) {
        int l = in[a], r = in[b];
        if (l > r) swap(l, r);
        return et[rmq.prod(l, r+1)];
    }
    long long dist(int a, int b) {
        long long ret = 0;
        int c = lca(a, b);
        if (a!=c) ret += depth[a] - depth[c];
        if (b!=c) ret += depth[b] - depth[c];
        return ret;
    }
};

// LCA with online cost changes
class LCA2 {
    struct Edge {
        int to, id;
        long long w;
    };
    bool done = false;
    int n, idx=0;
    vector<vector<Edge>> from;
    vector<int> et, in, ein, eout;  // EulerTour, in-order, edge-in-order, edge-out-order
    vector<long long> depth, ws;  // depth, weights
    segtree<S,op,e> rmq;
    fenwick_tree<long long> tree;
    void euler_tour(int v=0) {
        if(done) return;
        done = true;
        dfs(v);
        rmq = segtree<S,op,e>(et.size());
        tree = fenwick_tree<long long>(et.size());
        for(int i=0; i<(int)et.size(); ++i) {
            rmq.set(i, in[et[i]]);
        }
        for(int i=0; i<n-1; ++i) {
            tree.add(ein[i], ws[i]);
            tree.add(eout[i], -ws[i]);
        }
    }
    void dfs(int v, long long d=0, int p=-1) {
        in[v] = et.size();
        depth[v] = d;
        et.push_back(v);
        for(auto [nv, w, id]: from[v]) if (nv != p) {
            ein[id] = et.size()-1;
            dfs(nv, d+w, v);
            eout[id] = et.size()-1;
            et.push_back(v);
        }
    }
public:
    LCA2(int n): n(n),from(n),in(n),ein(n-1),eout(n-1),depth(n),ws(n-1) {}
    void add_edge(int a, int b, long long w=1) {
        from[a].emplace_back(b, w, idx);
        from[b].emplace_back(a, w, idx);
        ws[idx] = w;
        ++idx;
    };
    void change_cost(int id, long long w) {
        euler_tour();
        long long precost = ws[id];
        long long dif = w - precost;
        tree.add(ein[id], dif);
        tree.add(eout[id], -dif);
        ws[id] = w;
    }
    int lca(int a, int b) {
        euler_tour();
        int l = in[a], r = in[b];
        if (l > r) swap(l, r);
        return et[rmq.prod(l, r+1)];
    }
    long long dist(int a, int b) {
        euler_tour();
        long long ret = 0;
        int c = lca(a, b);
        if (a!=c) ret += depth[a] - depth[c];
        if (b!=c) ret += depth[b] - depth[c];
        return ret;
    }
    long long dist_with_changecost(int a, int b) {
        euler_tour();
        long long ret = 0;
        int c = lca(a, b);
        if (a!=c) ret += tree.sum(in[c], in[a]);
        if (b!=c) ret += tree.sum(in[c], in[b]);
        return ret;
    }
};
