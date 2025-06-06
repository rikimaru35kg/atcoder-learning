#include<bits/stdc++.h>
using namespace std;

template<class S, S(*op)(S, S), S(*e)()> struct SparseTable {
    int n, len=0;
    vector<vector<S>> a;
    vector<int> row; // width -> row of a
    SparseTable(int n): n(n), row(n+1) {
        for(int w=1; w<=n; w<<=1) {
            a.push_back(vector<S>(n+1-w, e()));
        }
        int i=0, rw=0;  // i: width for query, rw: row of a
        for(int w=1; w<=n; w<<=1) {
            while(i<=n && i<(w<<1)) row[i++] = rw;
            ++rw;
        }
    }
    void set(int i, S x) {
        assert(i>=0 && i<n);
        a[0][i] = x;
    }
    void build() {
        int rw=0;
        for(int w=2; w<=n; w<<=1) {
            for(int l=0; l<n+1-w; ++l) {
                a[rw+1][l] = op(a[rw][l], a[rw][l+w/2]);
            }
            ++rw;
        }
    }
    S prod(int l, int r) {
        assert(l>=0 && r<=n && l<=r);
        if(l==r) return e();
        int rw = row[r-l];
        int w = 1<<rw;
        return op(a[rw][l], a[rw][r-w]);
    }
    void dump() {
        #ifdef __DEBUG
        for(int i=0; i<n; ++i) cerr<<a[0][i]<<' ';
        cerr<<endl;
        #endif
    }
};