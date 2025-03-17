#include<bits/stdc++.h>
using namespace std;

struct Dijkstra {
    using LI = pair<long long,int>;
    using IL = pair<int,long long>;
    int n;
    vector<vector<IL>> from;
    Dijkstra(int n): n(n), from(n) {}
    void add_edge(int a, int b, long long c=1, bool both=false) {
        from[a].emplace_back(b, c);
        if(both) from[b].emplace_back(a, c);
    }
    vector<long long> dijkstra(int sv) {
        vector<long long> dist(n, 3e18);
        priority_queue<LI,vector<LI>,greater<LI>> que;
        auto push=[&](int v, long long d) {
            if(dist[v]<=d) return;
            dist[v] = d;
            que.emplace(d, v);
        };
        push(sv, 0);
        while(que.size()) {
            auto [d, v] = que.top(); que.pop();
            if(dist[v]!=d) continue;
            for(auto [nv, c]: from[v]) push(nv, d+c);
        }
        return dist;
    }
    vector<long long> bfs(int sv) {
        vector<long long> dist(n, 3e18);
        queue<int> que;
        auto push=[&](int v, long long d) {
            if(dist[v]<=d) return;
            dist[v] = d;
            que.push(v);
        };
        push(sv, 0);
        while(que.size()) {
            auto v = que.front(); que.pop();
            for(auto [nv, c]: from[v]) push(nv, dist[v]+c);
        }
        return dist;
    }
};