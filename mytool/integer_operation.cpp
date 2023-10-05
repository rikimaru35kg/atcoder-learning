#include <bits/stdc++.h>
using namespace std;

//! eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
//! primes = {(1,1), (2,3), (3,2), (5,1)}
//! NOTE: 1^1 is always included!!
vector<pair<long long, long long>> prime_factrization (long long n) {
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

vector<long long> listup_divisor(long long x, bool issort=false) {
    vector<long long> ret;
    for(long long i=1; i*i<=x; ++i) {
        if (x % i == 0) {
            ret.push_back(i);
            if (i*i != x) ret.push_back(x / i);
        }
    }
    if (issort) sort(ret.begin(), ret.end());
    return ret;
}

//! Calculate mod(a^b, mod)
//! a >= 0, b >= 0, mod > 0;
long long modpow(long long a, long long b, long long mod) {
	long long ans = 1;
	a %= mod;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}

//! Calculate a^b
//! a >= 0, b >= 0
long long spow(long long a, long long b) {
	long long ans = 1;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a;
		}
		a = a * a;
		b = (b >> 1);
	}
	return ans;
}

//! Stock factorias from 0 to n.
//! Specify empty vector as facts.
void stock_factorials (vector<long long> &facts, long long n, long long mod) {
    long long x = 1;
    for (long long i=0; i<=n; ++i) {
        (x *= max(1LL, i)) %= mod;
        facts.push_back(x);
    }
}

//! Calculate nCr based on factorias vector.
//! Please put modpow funtion above.
long long nCr_based_on_factorials(long long n, long long r, vector<long long> &facts, long long mod) {
    long long ret = 1;
    (ret *= facts[n]) %= mod;
    long long r_inv = modpow(facts[r], mod-2, mod);
    long long nr_inv = modpow(facts[n-r], mod-2, mod);
    (ret *= r_inv) %= mod;
    (ret *= nr_inv) %= mod;
    return ret;
}
