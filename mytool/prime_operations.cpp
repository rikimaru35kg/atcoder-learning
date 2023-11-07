#include <bits/stdc++.h>
using namespace std;


//! eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
//! primes = {(2,3), (3,2), (5,1)}
vector<pair<long long, long long>> prime_factorization (long long n) {
    vector<pair<long long, long long>> primes;
    if (n <= 1) return primes;
    for (long long k=2; k*k<=n; ++k) {
        if (n % k != 0) continue;
        primes.emplace_back(k, 0);
        while(n % k == 0) {
            n /= k;
            primes.back().second++;
        }
    }
    if (n != 1) primes.emplace_back(n, 1);
    return primes;
}


class Sieve {
    long long n;
    vector<long long> sieve;
    void add_prime(vector<pair<long long,long long>> &vp, long long m) {
        if (vp.size() == 0) {
            vp.emplace_back(m, 1);
            return;
        }
        if (vp.back().first == m) {
            ++vp.back().second;
        } else {
            vp.emplace_back(m, 1);
        }
    }
public:
    Sieve (long long n): n(n), sieve(n+1) {
        for (long long i=2; i<=n; ++i) {
            if (sieve[i] != 0) continue;
            for (long long k=i*i; k<=n; k+=i) {
                if (sieve[k] == 0) sieve[k] = i;
            }
        }
    }
    bool is_prime(long long k) {
        if (k <= 1 || k > n) return false;
        if (sieve[k] == 0) return true;
        return false;
    }
    vector<pair<long long,long long>> factorize(long long k) {
        vector<pair<long long,long long>> ret;
        if (k <= 1 || k > n) return ret;
        while (sieve[k] != 0) {
            add_prime(ret, sieve[k]);
            k /= sieve[k];
        }
        add_prime(ret, k);
        return ret;
    }
};

int main () {
    long long M = 1e5;
    Sieve sieve(M);
    for(int i=0; i<=M; ++i) {
        auto vp = sieve.factorize(i);
        auto vp2 = prime_factorization(i);
        if (vp != vp2) cout << "No" << endl;
    }
}