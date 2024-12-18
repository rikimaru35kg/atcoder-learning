#include <bits/stdc++.h>
using namespace std;


//! eg) 360 = 2^3 * 3^2 * 5^1;
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
    vector<int> mobius;
public:
    Sieve (long long n): n(n), sieve(n+1), mobius(n+1,1) {
        for (long long i=2; i<=n; ++i) {
            if (sieve[i] != 0) continue;
            sieve[i] = i;
            mobius[i] = -1;
            for (long long k=2*i; k<=n; k+=i) {
                if (sieve[k] == 0) sieve[k] = i;
                if ((k/i)%i==0) mobius[k] = 0;
                else mobius[k] *= -1;
            }
        }
    }
    bool is_prime(long long k) {
        if (k <= 1 || k > n) return false;
        if (sieve[k] == k) return true;
        return false;
    }
    vector<pair<long long,long long>> factorize(long long k) {
        vector<pair<long long,long long>> ret;
        if (k <= 1 || k > n) return ret;
        ret.emplace_back(sieve[k], 0);
        while (k != 1) {
            if (ret.back().first == sieve[k]) ++ret.back().second;
            else ret.emplace_back(sieve[k], 1);
            k /= sieve[k];
        }
        return ret;
    }
    int mu(long long k) { return mobius[k]; }
};

int main () {
    long long M = 1e5;
    Sieve sieve(M);
    for(int i=0; i<=M; ++i) {
        auto vp = sieve.factorize(i);
        auto vp2 = prime_factorization(i);
        if (vp != vp2) cout << "No" << endl;
    }
    cout << sieve.is_prime(5) << endl;
    cout << sieve.is_prime(91) << endl;
}