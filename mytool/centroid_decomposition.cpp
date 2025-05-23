#include<bits/stdc++.h>
using namespace std;

class CentroidDecomposition {
    int n;
    using IL = pair<int,long long>;
    vector<vector<IL>> from;
    vector<int> sz;
    vector<bool> cent;
    void cal_size(int sv) {
        auto dfs=[&](auto f, int v, int p=-1) -> void {
            sz[v] = 1;
            for(auto [nv,c]: from[v]) {
                if(nv==p || cent[nv]) continue;
                f(f, nv, v);
                sz[v] += sz[nv];
            }
        };
        dfs(dfs, sv);
    }
    int find_centroid(int sv) {
        int tot = sz[sv], ret = -1;
        auto dfs=[&](auto f, int v, int p=-1) -> void {
            bool ok = 2*(tot-sz[v])<=tot;
            for(auto [nv,c]: from[v]) {
                if(nv==p || cent[nv]) continue;
                f(f, nv, v);
                ok &= 2*sz[nv]<=tot;
            }
            if(ok) ret = v;
        };
        dfs(dfs, sv);
        assert(ret!=-1);
        return ret;
    }
public:
    CentroidDecomposition(int n): n(n), from(n), sz(n), cent(n) {}
    void add_edge(int a, int b, long long c=1) {
        from[a].emplace_back(b,c); from[b].emplace_back(a,c);
    }

    long long ans = 0;

    void decomposition(int sv) {
        // calculate value in the tree including sv
        cal_size(sv);
        int c = find_centroid(sv);  // find centroid of the tree
        cent[c] = true;
        //! DO NOT USE "sv" ANYMORE in this function

        ////////// algorithm here //////////

        ////////// algorithm here //////////

        for(auto [nv,d]: from[c]) if(!cent[nv]) decomposition(nv);
    }
};