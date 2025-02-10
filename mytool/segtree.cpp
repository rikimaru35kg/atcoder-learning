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
    void set_only(int i, S x, bool do_op=true) { // build() is needed afterwards
        assert(i>=0 && i<n);
        i += n;  // i is node id
        if(do_op) a[i] = op(a[i], x);
        else a[i] = x;
    }
    void set(int i, S x, bool do_op=true) {
        assert(i>=0 && i<n);
        set_only(i, x, do_op);
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
    S all_prod() { return a[1]; }
    int max_right(int l, auto f) {
        assert(l>=0 && l<=n);
        if(l==n) return n;
        l += n;  // l is node id
        S cum = e();  // cumulation of fixed span
        while(true) {
            while(~l&1) l>>=1; // go to parent if left node
            if(!f(op(cum, a[l]))) {  // search descendants
                while(l<n) {  // while l is not leaf
                    l<<=1;
                    if(f(op(cum, a[l]))) {
                        cum = op(cum, a[l]);
                        ++l;
                    }
                }
                return l-n;
            }
            cum = op(cum, a[l]); ++l;
            if((l&-l)==l) break;  // right most node -> return n
        }
        return n;
    }
    int min_left(int r, auto f) {
        assert(r>=0 && r<=n);
        if(r==0) return 0;
        r += n;  // r is node id(+1)
        S cum = e();  // cumulation of fixed span
        while(true) {
            --r; // r is node id
            while(r>1 && r&1) r>>=1; // go to parent if right node
            if(!f(op(a[r], cum))) {  // search descendants
                while(r<n) {  // while r is not leaf
                    r = r<<1|1;
                    if(f(op(a[r], cum))) {
                        cum = op(a[r], cum);
                        --r;
                    }
                }
                return r+1-n;
            }
            cum = op(a[r], cum);
            if((r&-r)==r) break;  // left most node -> return 0
        }
        return 0;
    }
};