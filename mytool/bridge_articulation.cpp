#include <bits/stdc++.h>
using namespace std;

struct Bridge {
    bool done = false;
    using PII = pair<int,int>;
    int n, m, idx;
    vector<vector<PII>> from;
    vector<int> ord, low, bridge, artcl;
    Bridge(int n): n(n), m(0), idx(0), from(n), ord(n,-1), low(n) {}
    void add_edge(int a, int b, int ei=-1) {
        if(ei==-1) {
            from[a].emplace_back(b, m); from[b].emplace_back(a, m);
            ++m;
        } else {
            from[a].emplace_back(b, ei); from[b].emplace_back(a, ei);
        }
    }
    void start_calc() {
        if(done) return;
        done = true;
        rep(i, n) if(ord[i]==-1) dfs(i);
    }
    void dfs(int v, int p=-1) {
        ord[v] = idx++; low[v] = ord[v];
        int c = 0;
        bool art = false;
        for(auto [nv,ei]: from[v]) if(nv!=p) {
            if(ord[nv]!=-1) {
                low[v] = min(low[v], ord[nv]); continue;
            }
            ++c;
            dfs(nv, v);
            low[v] = min(low[v], low[nv]);
            if(low[nv]>ord[v]) bridge.push_back(ei);
            if(low[nv]>=ord[v]) art = true;
        }
        if(p!=-1 && art) artcl.push_back(v);
        if(p==-1 && c>1) artcl.push_back(v);
    }
    vector<int> get_bridge() { start_calc(); return bridge;}
    vector<int> get_articulation() { start_calc(); return artcl;}
};