#include <bits/stdc++.h>
using namespace std;

struct BIT {
    long long size;
    vector<long long> bit;
    BIT (long long _n): size(_n+1), bit(_n+1, 0) {}

    void add (long long i, long long x) {
        for (; i < size; i += (i & -i)) {
            bit[i] += x;
        }
    }
    long long sum (long long i) {
        long long ret = 0;
        for (; i > 0; i -= (i) & (-i)) {
            ret += bit[i];
        }
        return ret;
    }
    long long sum_lower_bound(long long k) {
        long long x = 0, len = 1;
        while ((len << 1) < size) len <<= 1;
        while(len > 0) {
            if (x + len < size && bit[x + len] < k) {
                k -= bit[x + len];
                x += len;
            }
            len >>= 1;
        }
        return x + 1;
    }
};

class CoordinateCompression {
    bool init = false;
    vector<long long> vec;
public:
    void add (long long x) {vec.push_back(x);}
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        init = true;
    }
    long long operator() (long long x) {
        if (!init) compress();
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    }
    long long operator[] (long long i) {
        if (!init) compress();
        if (i < 0 || i >= (long long)vec.size()) return 3e18;
        return vec[i];
    }
    long long size () {return (long long)vec.size();}
#ifdef __DEBUG
    void print() {
        printf("---- cc print ----\ni: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", i);
        printf("\nx: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", vec[i]);
        printf("\n-----------------\n");
    }
#else
    void print() {}
#endif
};

long long get_inv_num(vector<long long> a) {
    CoordinateCompression cc;
    for (long long i=0; i<a.size(); ++i) cc.add(a[i]);
    long long n = cc.size();
    BIT bit(n);  // NOTE: BIT is 1-indexed!!
    long long ret = 0;
    for (long long i=0; i<a.size(); ++i) {
        ret += bit.sum(n) - bit.sum(cc(a[i])+1);
        bit.add(cc(a[i])+1, 1);
    }
    return ret;
}
