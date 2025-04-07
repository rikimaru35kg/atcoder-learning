#include <bits/stdc++.h>
using namespace std;

class HLD {
    int n;
    bool done = false;
    vector<int> idx, top, p, sz, depth, pei, eidx;
    vector<vector<pair<int,int>>> from;
    void cal_size() {  // calculate subtree size for each vertex
        auto dfs=[&](auto f, int v, int d=0, int par=-1) -> void {
            depth[v] = d; // depth
            sz[v] = 1;  // subtree size
            p[v] = par;  // parent
            for(auto [nv,ei]: from[v]) if(nv!=par) {
                f(f, nv, d+1, v);
                pei[nv] = ei;  // edge id for the parent
                sz[v] += sz[nv];
            }
        };
        dfs(dfs, 0);
    }
    void hld() {  // Heavy Light Decompsition
        if(done) return;
        done = true;
        cal_size();
        int ord = 0;
        auto dfs=[&](auto f, int v, int t, int par=-1) -> void {
            idx[v] = ord++;
            top[v] = t;
            tuple<int,int,int> maxsize(-1,-1,-1);
            for(auto [nv,ei]: from[v]) if(nv!=par) {
                maxsize = max(maxsize, {sz[nv],nv,ei});
            }
            auto [msz, mv, mei] = maxsize;
            if(msz==-1) return;
            // heavy edge
            eidx[mei] = idx[v];
            f(f, mv, t, v);
            // light edges
            for(auto [nv,ei]: from[v]) if(nv!=par && nv!=mv) {
                f(f, nv, nv, v);
            }
        };
        dfs(dfs, 0, 0);
    }
public:
    HLD(int n): n(n), idx(n), top(n), p(n), sz(n), depth(n),
                pei(n,-1), eidx(n-1,-1), from(n) {}
    void add_edge(int a, int b, int ei) {
        from[a].emplace_back(b,ei); from[b].emplace_back(a,ei);
    }
    pair<vector<pair<int,int>>,vector<int>> prod(int a, int b) {
        vector<pair<int,int>> spans;  // heavy paths
        vector<int> eis;  // light edges on a path a-b
        while(top[a]!=top[b]) {
            if(depth[top[a]]<depth[top[b]]) swap(a,b);
            spans.emplace_back(idx[top[a]],idx[a]);
            eis.push_back(pei[top[a]]);
            a = p[top[a]];
        }
        if(idx[a]>idx[b]) swap(a,b);
        spans.emplace_back(idx[a],idx[b]);
        return {spans, eis};
    }
    // get the index of the HLD sequence for each v
    vector<int> get_index()  { hld(); return idx; }
    // get the index of the HLD sequence for each ei
    // if ei==-1, then ei is a light edge (not on a path)
    vector<int> get_eindex() { hld(); return eidx; }
};