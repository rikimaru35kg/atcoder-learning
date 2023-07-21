#include <bits/stdc++.h>
using namespace std;

struct SCC {
    long long n;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num, rback_num;
    vector<vector<long long>> group;
    vector<bool> selected;
    SCC (long long _n): n(_n), from(_n), ifrom(_n) {}

    void add_edge (long long a, long long b) {
        from[a].push_back(b);
        ifrom[b].push_back(a);
    }

    void dfs1 (long long x, long long &bn) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (back_num[y] != -1) continue;
            if (selected[y]) continue;
            dfs1(y, bn);
        }
        back_num[x] = bn;
        rback_num[bn] = x;
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

    vector<vector<long long>> scc () {
        back_num.assign(n, -1);
        rback_num.assign(n, -1);
        selected.assign(n, false);
        long long bn = 0;
        for (long long i=0; i < n; ++i) {
            if (back_num[i] == -1) dfs1(i, bn);
        }
        sort(rback_num.begin(), rback_num.end());
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            long long x = rback_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            group.push_back(emp);
            dfs2(x, group.back());
        }
        return group;
    }
};

int main () {

}