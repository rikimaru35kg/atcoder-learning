#include <bits/stdc++.h>>
using namespace std;

// return {gcd(a,b), x, y}, where ax + by = gcd(a, b) 
tuple<long long,long long,long long> extgcd(long long a, long long b) {
    if (b == 0) return make_tuple(a, 1, 0);
    auto [g, x, y] = extgcd(b, a%b);
    return make_tuple(g, y, x - a/b*y);
}
