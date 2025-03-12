#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    long long size;
    vector<T> bit;
    BIT (int _n): size(_n+1), bit(_n+1) {}
    void add(int i, T x) {
        ++i;  // 0-index -> 1_index
        assert(i>=1 && i<size);
        for(; i<size; i+=i&-i) bit[i] += x;
    }
    void set(int i, T x) {
        assert(i>=0 && i<size-1);
        T pre = sum(i,i+1);
        add(i, x-pre);
    }
    T sum(int l, int r) {  // [l,r) half-open interval
        return sum0(r-1) - sum0(l-1);
    }
    T sum0(int i) {  // [0,i] closed interval
        ++i;  // 0-index -> 1_index
        assert(i>=0 && i<size); // i==0 -> return 0
        T ret(0);
        for(; i>0; i-=i&-i) ret += bit[i];
        return ret;
    }
    int lower_bound(T x) {
        int t=0, w=1;
        while(w<size) w<<=1;
        for(; w>0; w>>=1) {
            if(t+w<size && bit[t+w]<x) { x -= bit[t+w]; t += w; }
        }
        return t;
    }
    void dump() {
        #ifdef __DEBUG
        for(int i=0; i<size-1; ++i) { cerr<<sum(i,i+1)<<' '; } cerr<<'\n';
        #endif
    }
};

template<typename T>
struct RangeBIT {
    long long size;
    vector<vector<T>> bit;
    RangeBIT (int _n): size(_n+1), bit(2, vector<T>(_n+1)) {}
    void add(int l, int r, T x) {  // [l,r) half-open interval
        add_sub(0, l, -x*(l-1)); add_sub(0, r, x*(r-1));
        add_sub(1, l, x); add_sub(1, r, -x);
    }
    T sum(int l, int r) { // [l,r) half-open interval
        return sum0(r-1) - sum0(l-1);
    }
    T sum0(int i) {  // [0,i] closed interval
        return sum_sub(0,i) + sum_sub(1,i)*i;
    }
    T get(int i) { return sum(i, i+1); }
    void add_sub(int p, int i, T x) {
        ++i;  // 0-index -> 1_index
        assert(i>=1 && i<=size); // i<=size is not necessarily needed (ignored afterwards anyway)
        for(; i<size; i+=i&-i) bit[p][i] += x;
    }
    T sum_sub(int p, int i) {  // [0,i] closed interval
        ++i;  // 0-index -> 1_index
        assert(i>=0 && i<size); // i==0 -> return 0
        T ret(0);
        for(; i>0; i-=i&-i) ret += bit[p][i];
        return ret;
    }
    void dump() {  // for debug
        #ifdef __DEBUG
        for(ll i=0; i<size-1; ++i) { cerr << get(i) << ' '; }
        cerr << endl;
        #endif
    }
};

template<typename T>
class SpanBIT {
    long long size;
    vector<T> bit;
    void _add (long long i, T x) {
        if(i<0 || i>=size-1) assert(0&&"Error: not 0<=i<=n in SpanBIT _add(i,x)");
        ++i;
        for (; i<size; i+=i&-i) bit[i] += x;
    }
    T _sum (long long i) {
        if(i<0 || i>=size-1) assert(0&&"Error: not 0<=i<=n in SpanBIT _sum(i)");
        ++i;
        T ret = 0;
        for (; i>0; i-=i&-i) ret += bit[i];
        return ret;
    }
public:
    SpanBIT (long long _n): size(_n+2), bit(_n+2, 0) {}
    // ![CAUTION]   0 <= l,r <= _n
    void add (long long l, long long r, T x) { // [l,r)
        if(l<=r) {_add(l, x); _add(r, -x);}
        else {
            _add(l, x); _add(size-2, -x);
            _add(0, x); _add(r, -x);
        }
    }
    T get (long long i) {
        return _sum(i);
    }
};

int main () {
    SpanBIT<int> bit(5);
    bit.add(0, 5, 3);
    for(int i=0; i<5; ++i) cout << bit.get(i) << endl;

}