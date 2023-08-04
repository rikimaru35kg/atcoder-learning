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
        back_num.assign(n, -1);
        selected.assign(n, false);
        bn = 0;
        for (long long i=0; i < n; ++i) {
            if (!selected[i]) dfs1(i);
        }
        reverse(back_num.begin(), back_num.end());
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            long long x = back_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            dfs2(x, emp);
            group.push_back(emp);
        }
        return group;
    }

private:
    long long n, bn;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num;
    vector<bool> selected;

    void dfs1 (long long x) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (selected[y]) continue;
            dfs1(y);
        }
        back_num[bn] = x;
        ++bn;
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

