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

int main () {
    BIT bit(5);
    bit.add(1, 1);
    bit.add(3, 1);
    bit.add(5, 1);
    for (int i = 1; i <= 5; i++) cout << bit.sum(i) << endl;
    cout << endl;
    for (int i = 0; i <= 4; i++) printf("%d: %lld\n", i, bit.sum_lower_bound(i));

}