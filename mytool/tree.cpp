#include <bits/stdc++.h>
using namespace std;

struct Diameter {
    int n, a, b, d; bool done=false;
    vector<vector<int>> from;
    Diameter(int n): n(n), from(n) {}
    void add_edge(int a, int b) {
        from[a].push_back(b); from[b].push_back(a);
    }
    pair<int,int> dfs(int v, int d=0, int p=-1) {
        pair<int,int> ret(d, v);
        for(auto nv: from[v]) if(nv!=p) {
            chmax(ret, dfs(nv, d+1, v));
        }
        return ret;
    }
    pair<int,int> get_end_points() {
        if(done) return {a,b};
        done = true;
        a = dfs(0).second;
        auto [dtmp, btmp] = dfs(a);
        b = btmp, d = dtmp;
        return {a,b};
    }
    int get_diameter() {
        get_end_points();
        return d;
    }
};