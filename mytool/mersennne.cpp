#include <bits/stdc++.h>
using namespace std;

long long mersenne(long long mn, long long mx) {
    // random_device rd;  // slow
    // static mt19937_64 mt64(rd());  // slow
    static mt19937_64 mt64(0);
    uniform_int_distribution<long long> get(mn, mx);
    return get(mt64);
}
