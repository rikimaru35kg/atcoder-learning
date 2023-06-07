#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define repr(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (int i = k; i < (int)(n); i++)

ll modpow(ll a, ll b, ll mod) {
    // Calculate mod(a^b, mod)
    // a >= 0, b >= 0, mod > 0;
	ll ans = 1;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}

ll digits(ll x) {
    ll ret = 0;
    if (x == 0) return 1;
    while (x > 0) {
        x /= 10;
        ret++;
    }
    return ret;
}

const ll MOD = 1000000007;

int main() {
    ll L, R; cin >> L >> R;

    ll d_start = digits(L);
    ll d_end = digits(R);

    ll cnt = 0;
    repk (i, d_start, d_end + 1) {
        ll a0, an;
        if (i == d_start) {
            a0 = L;
        }
        else {
            a0 = 1;
            rep (j, i - 1) a0 *= 10;
        }
        if (i == d_end) {
            an = R;
        }
        else {
            an = 1;
            rep (j, i) an *= 10;
            an--;
        }
        ll x = i * (a0%MOD + an%MOD) % MOD * ((an - a0)%MOD + 1) % MOD;
        x = x * modpow(2, MOD-2, MOD) % MOD;
        cnt = (cnt + x) % MOD;
    }

    cout << cnt << endl;

}