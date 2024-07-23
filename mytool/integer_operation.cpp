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

//! n,k >= 0
//! O(log kM) M=3e18
long long kth_root(long long n, long long k) {
    if(k<=0 || n<0) assert(0&&"[Error]k<=0 or n<0 in the function of kth_root.");
    auto f=[&](long long x) -> bool {
        long long x_to_kpow = 1;
        for(long long i=0; i<k; ++i) {
            if(x>n/x_to_kpow) return false;
            x_to_kpow *= x;
        }
        return x_to_kpow <= n;
    };
    long long l = 0, r = 3e18;
    while(r-l>1) {
        long long m = (l+r)/2;
        if(f(m)) l = m;
        else r = m;
    }
    return l;
}

//! no mod nCr
//! return value shall be within long long range
class Pascal {
    int mx = 66;
    vector<vector<long long>> comb;
public:
    Pascal () :comb(mx+1, vector<long long>(mx+1)) {
        comb[0][0] = 1;
        for (int i=0; i<mx; ++i) for (int j=0; j<=i; ++j) {
            comb[i+1][j] += comb[i][j];
            comb[i+1][j+1] += comb[i][j];
        }
    }
    long long nCr(int n, int r) {
        if (n < 0 || r < 0 || n < r) return 0;
        if (n > mx) {
            cout << "[ClassPascalError@nCr] n is too large (shall be <=66)" << endl;
            assert(0);
        }
        return comb[n][r];
    }
};

// Combination for very small r
long long nCr (long long n, long long r) {
    long long ninf = 3e18;
    if(n<0 || r>n || r<0) return 0;
    r = min(r, n-r);
    long long ret = 1;
    for(long long k=1; k<=r; ++k) {
        if(n-k+1 > (ninf+ret-1)/ret) {
            assert(0&&"[Error:nCr] Too large return value.");
        }
        ret *= n-k+1;
        ret /= k;
    }
    return ret;
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
        ifacts[mx] = modpow(facts[mx], mod-2);
        for (long long i=mx-1; i>=0; --i) ifacts[i] = ifacts[i+1] * (i+1) % mod;
    }
    long long operator()(long long n, long long r) {
        return nCr(n, r);
    }
    long long nCr(long long n, long long r) {
        if (r < 0 || r > n || n < 0 || n > mx) return 0;
        return facts[n] * ifacts[r] % mod * ifacts[n-r] % mod;
    }
    long long nPr(long long n, long long r) {
        if (r < 0 || r > n || n < 0 || n > mx) return 0;
        return facts[n] * ifacts[n-r] % mod;
    }
    long long nHr(long long n, long long r, bool one=false) {
        if(!one) return nCr(n+r-1, r);
        else return nCr(r-1, n-1);
    }
    long long get_fact(long long n) {
        if (n > mx) return 0;
        return facts[n];
    }
    long long get_factinv(long long n) {
        if (n > mx) return 0;
        return ifacts[n];
    }
    long long modpow(long long a, long long b) {
        if (b == 0) return 1;
        a %= mod;
        long long child = modpow(a, b/2);
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

//! Legendre's Formura
//! ret = Σ{i=1-∞}floor(n/p^i)
long long legendre_formula(long long n, long long p) {
    long long ret = 0;
    while(n) {
        ret += n/p;
        n /= p;
    }
    return ret;
}

int main () {
    long long K; cin >> K;
    auto v = listup_divisor(K, true);
    cout << v.size() << endl;
    // Pascal p;
    // cout << p.nCr(66, 0) << endl;
    // cout << p.nCr(66, 66) << endl;
    // cout << p.nCr(67, 67) << endl;

}
