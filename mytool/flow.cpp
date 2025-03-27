#include<bits/stdc++.h>
using namespace std;

class MaxFlow {
    int n;
    vector<int> dist, iter;
    long long inf = numeric_limits<long long>::max();
    struct Edge {
        int to; long long cap; int rev;
        Edge(int to, long long cap, int rev): to(to), cap(cap), rev(rev) {}
    };
    void bfs(int sv) {
        dist.assign(n, -1);
        queue<int> que;
        dist[sv] = 0; que.push(sv);
        while(que.size()) {
            auto v = que.front(); que.pop();
            for(auto [nv,cap,rev]: from[v]) {
                if(cap==0 || dist[nv]!=-1) continue;
                dist[nv] = dist[v]+1, que.push(nv); 
            }
        }
    }
    long long dfs(int v, int t, long long f) {
        if(v==t) return f;
        for(int &i=iter[v]; i<int(from[v].size()); i++) {
            auto [nv,cap,rev] = from[v][i];
            if(dist[nv]<=dist[v] || cap==0) continue;
            long long res = dfs(nv, t, min(f,cap));
            if(res) {
                from[v][i].cap -= res;
                from[nv][rev].cap += res;
                return res;
            }
        }
        return 0;
    }
public:
    vector<vector<Edge>> from;
    MaxFlow(int n): n(n), from(n) {}
    void add_edge(int a, int b, long long c) {
        from[a].emplace_back(Edge(b,c,from[b].size()));
        from[b].emplace_back(Edge(a,0,from[a].size()-1));
    }
    long long flow(int s, int t) {
        long long ret = 0;
        while(true) {
            bfs(s);
            if(dist[t]==-1) return ret;
            iter.assign(n, 0);
            long long now=0;
            while((now=dfs(s,t,inf))>0) {
                ret += now;
            }
        }
        return 0;
    }
};