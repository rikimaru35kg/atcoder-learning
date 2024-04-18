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

class SpanBIT {
    long long size;
    vector<long long> bit;
    void _add (long long i, long long x) {
        if(i<0 || i>=size-1) assert(0&&"Error: not 0<=i<=n in SpanBIT _add(i,x)");
        ++i;
        for (; i<size; i+=i&-i) bit[i] += x;
    }
    long long _sum (long long i) {
        if(i<0 || i>=size-1) assert(0&&"Error: not 0<=i<=n in SpanBIT _sum(i)");
        ++i;
        long long ret = 0;
        for (; i>0; i-=i&-i) ret += bit[i];
        return ret;
    }
public:
    SpanBIT (long long _n): size(_n+2), bit(_n+2, 0) {}
    void add (long long l, long long r, long long x) { // [l,r)
        if(l<=r) {_add(l, x); _add(r, -x);}
        else {
            _add(l, x); _add(size-2, -x);
            _add(0, x); _add(r, -x);
        }
    }
    long long get (long long i) {
        return _sum(i);
    }
};

int main () {
    SpanBIT bit(5);
    bit.add(0, 5, 3);
    for(int i=0; i<5; ++i) cout << bit.get(i) << endl;

}