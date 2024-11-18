#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll modpower(ll a, ll r, ll mod){ //a^r
    ll x = 1;
    if (r < 0) r = r%(mod-1)+mod-1;
    a %= mod;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a, ll mod) {
    //a*ret%mod == gcd(a, mod)
    ll x = 0, y = 1, u = 1, v = 0, b = mod;
    while (b != 0) {
        ll q = a/b;
        a %= b;
        swap(a, b);
        u -= q*x;
        swap(u, x);
        v -= q*y;
        swap(y, v);
    }
    if (u > 0) return u;
    else return u+mod;
}

vector<ll> fact;
vector<ll> invfact;

void set_fact(ll n, ll mod){
    fact.resize(n+1, 1);
    invfact.resize(n+1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = modinv(fact[n], mod);
    for (ll i = n-1; i >= 2; i--) {
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }
    return;
}

ll comb(ll n, ll k, ll mod) {
    if (k > n || k < 0) return 0;
    if (k == n || k == 0) return 1;
    return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}
int main() {
    int R, C;
    cin >> R >> C;
    ll mod = 1e9+7;
    int N;
    cin >> N;
    int u = R, d = 1, l = C, r = 1;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        u = min(u, x);
        d = max(d, x);
        l = min(l, y);
        r = max(r, y);
    }
    set_fact(10000, mod);
    ll ans = 1;
    for (int i = 1; i <= (d-u+1)*(r-l+1)-N; i++) {
        ans = ans*i%mod;
    }
    vector<vector<ll>> dp(R+1, vector<ll>(C+1, 0));
    dp[d-u+1][r-l+1] = 1;
    for (int i = d-u+1; i <= R; i++) {
        for (int j = r-l+1; j <= C; j++) {
            if (i == d-u+1 && j == r-l+1) continue;
            dp[i][j] = (dp[i-1][j]*fact[j]+dp[i][j-1]*fact[i])%mod;
        }
    }
    ans = ans*dp[R][C]%mod;
    ans = ans*comb(R-(d-u+1), u-1, mod)%mod;
    ans = ans*comb(C-(r-l+1), l-1, mod)%mod;
    cout << ans << endl;
    return 0;
}