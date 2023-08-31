#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> prime_factrization (long long n) {
    // eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
    // primes = {(1,1), (2,3), (3,2), (5,1)}
    // NOTE: 1^1 is always included!!
    vector<pair<long long, long long>> primes;
    primes.emplace_back(1, 1);
    long long rem = n;
    for (long long k=2; k*k<=n; ++k) {
        long long num = 0;
        while(rem % k == 0) {
            ++num;
            rem /= k;
        }
        if (num > 0) primes.emplace_back(k, num);
    }
    if (rem != 1) primes.emplace_back(rem, 1);
    return primes;
}
