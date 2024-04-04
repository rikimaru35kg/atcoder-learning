#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

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
