#include <bits/stdc++.h>
using namespace std;


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


//! Only when <= 1e6
//! If not, use Combination2 class below.
class Combination {
    long long mx, mod;
    vector<long long> facts, ifacts;
public:
    // argument mod must be a prime number!!
    Combination(long long mx, long long mod): mx(mx), mod(mod), facts(mx+1), ifacts(mx+1) {
        facts[0] = 1;
        for (long long i=1; i<=mx; ++i) facts[i] = facts[i-1] * i % mod;
        ifacts[mx] = modpow(facts[mx], mod-2, mod);
        for (long long i=mx-1; i>=0; --i) ifacts[i] = ifacts[i+1] * (i+1) % mod;
    }
    long long nCr(long long n, long long r) {
        if (r < 0 || r > n || n < 0 || n > mx) return 0;
        return facts[n] * ifacts[r] % mod * ifacts[n-r] % mod;
    }
    long long nPr(long long n, long long r) {
        if (r < 0 || r > n || n < 0 || n > mx) return 0;
        return facts[n] * ifacts[n-r] % mod;
    }
    long long get_fact(long long n) {
        if (n > mx) return 0;
        return facts[n];
    }
    long long get_factinv(long long n) {
        if (n > mx) return 0;
        return ifacts[n];
    }
    long long modpow(long long a, long long b, long long mod) {
        if (b == 0) return 1;
        a %= mod;
        long long child = modpow(a, b/2, mod);
        if (b % 2 == 0) return child * child % mod;
        else return a * child % mod * child % mod;
    }
};

//! Use this class if n >= 1e7 && r <= 1e6
class Combination2 {
    long long mod;
public:
    Combination2 (long long mod): mod(mod) {}
    long long nCr (long long n, long long r) {
        r = min(n-r , r);
        long long r_fact = 1;
        for (long long i=1; i<=r; ++i) (r_fact *= i) %= mod;
        long long r_fact_inv = modpow(r_fact, mod-2, mod);
        long long ret = r_fact_inv;
        for (long long i=0; i<r; ++i) (ret *= (n-i)) %= mod;
        return ret;
    }
    long long modpow(long long a, long long b, long long mod) {
        long long ret = 1;
        a %= mod;
        while (b > 0) {
            if ((b & 1) == 1) ret = ret * a % mod;
            a = a * a % mod;
            b = (b >> 1);
        }
        return ret;
    }
};


int main () {
    Combination comb(100, 1e9+7);
    cout << comb.nCr(6, 2) << endl;
    cout << comb.nPr(6, 2) << endl;
    cout << comb.nCr(6, 6) << endl;
    cout << comb.nCr(10, 2) << endl;
    cout << comb.nCr(10, 10) << endl;
    cout << comb.nCr(10, 0) << endl;
    cout << comb.nCr(10, 11) << endl;
    cout << comb.get_fact(10) << endl;
    cout << comb.nPr(11, 3) << endl;
}
