#include <bits/stdc++.h>
using namespace std;

struct SCC {
    SCC (long long _n): n(_n), from(_n), ifrom(_n) {}

    void add_edge (long long a, long long b) {
        from[a].push_back(b);
        ifrom[b].push_back(a);
    }

    vector<vector<long long>> scc () {
        vector<vector<long long>> group;
        back_num.clear();
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            if (!selected[i]) dfs1(i);
        }
        selected.assign(n, false);
        for (long long i=n-1; i >= 0; --i) {
            long long x = back_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            dfs2(x, emp);
            group.push_back(emp);
        }
        return group;
    }

private:
    long long n;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num;
    vector<bool> selected;

    void dfs1 (long long x) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (selected[y]) continue;
            dfs1(y);
        }
        back_num.push_back(x);
    }

    void dfs2 (long long x, vector<long long> &vec) {
        selected[x] = true;
        vec.push_back(x);
        for (auto y: ifrom[x]) {
            if (selected[y]) continue;
            dfs2(y, vec);
        }
    }
};


