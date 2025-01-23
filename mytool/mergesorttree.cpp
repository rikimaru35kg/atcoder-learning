#include <bits/stdc++.h>
using namespace std;

struct MergeSortTree {
    int n;
    vector<vector<long long>> a, s; // s: cumulated sum
    MergeSortTree(int mx) {
        n = 1;
        while(n<mx) n<<=1;
        a.resize(n*2);
        s.resize(n*2, vl(1));
    }
    void set_only(int i, long long x) { // build() is needed afterwards
        assert(i>=0 && i<n);
        i += n;
        a[i] = {x};
        s[i] = {0, x};
    }
    void set(int i, long long x) { // [CAUTION] O(N*log(N)) for 1 execution
        assert(i>=0 && i<n);
        set_only(i, x);
        i += n; i>>=1;
        while(i) {
            update(i);
            i>>=1;
        }
    }
    void update(int i) {
        assert(i>=1 && i<2*n);
        int l = i<<1, r = l|1;
        a[i] = vector<long long>();
        merge(a[l].begin(),a[l].end(),a[r].begin(),a[r].end(),
              back_inserter(a[i]));
        int m = a[i].size();
        s[i].resize(m+1);
        for(int j=0; j<m; ++j) s[i][j+1] = s[i][j] + a[i][j];
    }
    void build() {
        for(int i=n-1; i>=1; --i) { update(i); }
    }
    long long get(int i, long long x) { // i = nodeid - n
        i += n;
        assert(i>=1 && i<2*n);
        int idx = upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
        return s[i][idx];
    }
    long long prod(int ql, int qr, long long x) { // cumsum s.t. A[i]<=x
        assert(ql>=0 && qr<=n);
        auto f=[&](auto f, int l, int r, long long i) -> long long {
            if(r<=ql || l>=qr) return 0;
            if(l>=ql && r<=qr) return get(i-n, x);
            int m = (l+r)/2;
            long long ret = f(f, l, m, i<<1) + f(f, m, r, (i<<1)|1);
            return ret;
        };
        long long ret = f(f, 0, n, 1);
        return ret;
    }
};