#include <bits/stdc++.h>
using namespace std;

//! e.g.) n=6, k=2, digit=5
//! ret = {0, 0, 1, 1, 0}
//! e.g.) n=10, k=3
//! ret = {1, 0, 1}
vector<long long> num_to_kbase (long long n, long long k, long long digit=0) {
    vector<long long> ret;
    while (n > 0) {
        ret.push_back(n % k);
        n /= k;
    }
    if (digit == 0) {
        reverse(ret.begin(), ret.end());
        return ret;
    }

    while ((long long)ret.size() < digit) {
        ret.push_back(0);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

//! e.g.) kbase_vec={0, 0, 1, 1, 0}, k=2
//! ret = 6
//! e.g.) kbase_vec = {1, 0, 1}, k=3
//! ret = 10
long long kbase_to_num (vector<long long> kbase_vec, long long k) {
    long long ret = 0;
    for (long long i=0; i<(long long)kbase_vec.size(); ++i) {
        ret = ret*k + kbase_vec[i];
    }
    return ret;
}

int main () {
    vector<long long> a = num_to_kbase(123456, 5, 100);
    vector<long long> b = num_to_kbase(10, 3);
    long long c = kbase_to_num(a, 5);
    long long d = kbase_to_num(b, 3);
    printf("%lld %lld\n", c, d);
}