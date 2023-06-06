#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll modpower(ll a, ll b, ll mod) {
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

vl lto2(ll x) {
    vl y;

    if (x == 0) {
        y.push_back(0);
        return y;
    }

    while (x > 0) {
        if ((x & 1) == 0) y.push_back(0);
        else y.push_back(1);
        x = (x >> 1);
    }
    return y;
}

int main() {
    ll N, K; cin >> N >> K;
    const ll MOD = 1000000007;

    if (N == 1) {
        cout << K << endl;
        return 0;
    }
    if (N == 2) {
        cout << K * (K-1) << endl;
        return 0;
    }

    ll M = N - 2;
    vl Mque = lto2(M);
    ll _tmp = (K-2) % MOD;
    vl _mods;
    rep (i, Mque.size()) {
        _mods.push_back(_tmp);
        _tmp = _tmp * _tmp % MOD;
    }

    ll ans = 1;
    rep (i, Mque.size()){
        if (Mque.at(i) == 0) continue;
        ans = ans * Mque.at(i) % MOD * _mods.at(i) % MOD;
    }
    ans = modpower(K-2, N-2, MOD) * K % MOD * (K-1) % MOD;

    cout << ans << endl;
}
