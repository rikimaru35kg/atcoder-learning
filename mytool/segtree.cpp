#include <bits/stdc++.h>
using namespace std;

template <class S, S(*op)(S, S), S(*e)()>
struct SegTree {
    int n;
    vector<S> a;
    SegTree(int mx) {
        n = 1;
        while(n<mx) n<<=1;
        a.resize(n*2, e());
    }
    void set_only(int i, S x) { // build() is needed afterwards
        assert(i>=0 && i<n);
        i += n;  // i is node id
        a[i] = x;
    }
    void set(int i, S x) {
        assert(i>=0 && i<n);
        set_only(i, x);
        i += n; i>>=1;  // i is node id
        while(i) {
            update(i);
            i>>=1;
        }
    }
    void update(int i) {  // i is node id
        assert(i>=1 && i<2*n);
        int l = i<<1, r = l|1;  // l,r are children
        a[i] = op(a[l], a[r]);
    }
    void build() {
        for(int i=n-1; i>=1; --i) { update(i); }
    }
    S get(int i) { // i = nodeid - n
        i += n;
        assert(i>=1 && i<2*n);
        return a[i];
    }
    S prod(int ql, int qr) {
        assert(ql>=0 && qr<=n);
        auto f=[&](auto f, int l, int r, int i) -> S {
            if(r<=ql || l>=qr) return e();
            if(l>=ql && r<=qr) return get(i-n);
            int m = (l+r)/2;
            S ret = op(f(f, l, m, i<<1), f(f, m, r, (i<<1)|1));
            return ret;
        };
        S ret = f(f, 0, n, 1);
        return ret;
    }
};
