#include <bits/stdc++.h>
using namespace std;

struct Diameter {
    int n, a, b; bool done=false;
    long long d;
    using PRII = pair<int,int>;
    using PRLI = pair<long long,int>;
    vector<vector<PRLI>> from;
    Diameter(int n): n(n), from(n) {}
    void add_edge(int a, int b, long long c=1) {
        from[a].emplace_back(b, c);
        from[b].emplace_back(a, c);
    }
    PRLI dfs(int v, long long d=0, int p=-1) {
        PRLI ret(d, v);
        for(auto [nv,c]: from[v]) if(nv!=p) {
            chmax(ret, dfs(nv, d+c, v));
        }
        return ret;
    }
    PRII get_end_points() {
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
    // dist is input, but return value practically
    void caldist(int sv, vector<long long> &dist) {
        auto dfs=[&](auto f, int v, long long d=0, int p=-1) -> void {
            dist[v] = d;
            for(auto [nv,c]: from[v]) if(nv!=p) {
                f(f, nv, d+c, v);
            }
        };
        dfs(dfs, sv);
    }
};