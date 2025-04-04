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

    ////////// data here //////////
    long long ans=0;
    vector<long long> A;
    void initialize(vector<long long> &a) {
        for(auto x: a) A.push_back(x);
    }
    long long get_ans() {return ans;}
    ////////// data here //////////

    void decomposition(int sv) {
        cal_size(sv);
        int c = find_centroid(sv);
        cent[c] = true;
        //! DO NOT USE "sv" ANYMORE in this function

        ////////// algorithm here //////////
        unordered_map<long long,long long> cnt, sum;
        cnt[A[c]] = 1, sum[A[c]] = 0;
        for(auto [nv,d]: from[c]) if(!cent[nv]) {
            vector<pair<long long,long long>> data;
            auto dfs=[&](auto f, int v, int d, int p=-1) -> void {
                data.emplace_back(A[v], d);
                for(auto [nv,c]: from[v]) {
                    if(nv==p || cent[nv]) continue;
                    f(f, nv, d+1, v);
                }
            };
            dfs(dfs, nv, 1);
            for(auto [a,d]: data) {
                ans += d*cnt[a] + sum[a];
            }
            for(auto [a,d]: data) {
                cnt[a]++;
                sum[a] += d;
            }
        }
        ////////// algorithm here //////////

        for(auto [nv,d]: from[c]) if(!cent[nv]) decomposition(nv);
    }
};