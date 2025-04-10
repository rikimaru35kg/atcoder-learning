#include <bits/stdc++.h>
using namespace std;

template <class S, S(*op)(S, S), S(*e)()> class SegTree {
    int n, mx;
    vector<S> a;
    void climb(int i) {  while(i){ update(i); i>>=1; } }
    void update(int i) {  a[i] = op(a[i<<1], a[i<<1|1]); }
public:
    SegTree(int mx): mx(mx) {
        n = 1;
        while(n<mx) n<<=1;
        a.resize(n*2, e());
    }
    void set_only(int i, S x, bool do_op=false) { // build() is needed afterwards
        assert(i>=0 && i<mx);
        i += n;  // i is node id
        if(do_op) a[i] = op(a[i], x);
        else a[i] = x;
    }
    void set(int i, S x) {
        assert(i>=0 && i<mx);
        set_only(i, x);
        climb((i+n)>>1);
    }
    void set_and_op(int i, S x) {
        assert(i>=0 && i<mx);
        set_only(i, x, true);
        climb((i+n)>>1);
    }
    void build() { for(int i=n-1; i>=1; --i) { update(i); } }
    S get(int i) {
        assert(i>=0 && i<mx);
        return a[i+n];
    }
    S prod(int l, int r) {
        assert(l>=0 && r<=mx && l<=r);
        S lft = e(), rgt = e();
        l += n, r += n;
        while(l<r) {
            if(l&1) lft = op(lft, a[l++]);
            if(r&1) rgt = op(a[--r], rgt);
            l>>=1, r>>=1;
        }
        return op(lft, rgt);
    }
    S all_prod() { return a[1]; }
    int max_right(int l, auto f) {
        assert(l>=0 && l<=mx);
        assert(f(e()));
        if(l==mx) return mx;
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
        return mx;
    }
    int min_left(int r, auto f) {
        assert(r>=0 && r<=mx);
        assert(f(e()));
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
    void dump() {
        #ifdef __DEBUG
        for(int i=0; i<mx; ++i) { fprintf(stderr, "%lld ", get(i)); }
        cerr<<endl;
        #endif
    }
};

template<class S, S(*op)(S,S), S(*e)()> class DualSegTree {
    int n, mx;
    vector<S> a;
public:
    DualSegTree(int mx): mx(mx) {
        n = 1;
        while(n<mx) n<<=1;
        a.resize(2*n, e());
    }
    void set(int i, S x) {
        assert(i>=0 && i<mx);
        a[i+n] = x;
    }
    void set_and_op(int i, S x) {
        assert(i>=0 && i<mx);
        a[i+n] = op(a[i+n], x);
    }
    void apply(int l, int r, S x) {
        assert(l>=0 && r<=mx && l<=r);
        l += n, r += n;
        while(l<r) {
            if(l&1) a[l] = op(a[l],x), ++l;
            if(r&1) --r, a[r] = op(a[r],x);
            l>>=1, r>>=1;
        }
    }
    S get(int i) {
        assert(i>=0 && i<mx);
        i += n;
        S ret = e();
        while(i) { ret = op(ret, a[i]); i>>=1; }
        return ret;
    }
    void dump() {
    #ifdef __DEBUG
        for(int i=0; i<mx; ++i) { fprintf(stderr, "%lld ", get(i)); }
        cerr<<endl;
    #endif
    }
};