#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
typedef pair<double, double> Paird;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vpd vector<Paird>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvd vector<vector<vector<double>>>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;

struct BIT {
    ll n;
    vl bit;
    BIT (ll _n): n(_n+1), bit(_n+1) {}

    void add(ll i, ll x) {
        for(ll idx = i; idx<n; idx += idx&-idx) {
            bit[idx] += x;
        }
    }
    ll sum(ll i) {
        ll ret = 0;
        for (ll idx=i; idx>0; idx -= idx&-idx) {
            ret += bit[idx];
        }
        return ret;
    }
    ll sum_lower_bound(ll x) {
        ll s = 0, len = 1;
        while(len<<1 < n) len<<=1;
        while(len>=1) {
            if (s+len >= n || bit[s+len] >= x) {
                len>>=1;
                continue;
            }
            x -= bit[s+len];
            s += len;
            len >>= 1;
        }
        return s+1;
    }
};

int main () {
    ll N, M, K; cin >> N >> M >> K;
    vl A(N);
    rep (i, N) cin >> A[i];
    map<ll,ll> cc, ccr;
    rep (i, N) cc[A[i]] = 0;
    ll idx = 1;
    for (auto [k, v]: cc) {
        cc[k] = idx;
        ccr[idx] = k;
        ++idx;
    }
    ll num = SIZE(cc);

    BIT bit(num);
    BIT bit_sum(num);
    rep (i, M) {
        ll a = cc[A[i]];
        bit.add(a, 1);
        bit_sum.add(a, ccr[a]);
    }

    rep (i, N-M+1) {
        ll x = bit.sum_lower_bound(K);
        ll ans = bit_sum.sum(x);
        ll r = bit.sum(x) - K;
        ans -= r * ccr[x];
        printf("%lld ", ans);

        if (i == N-M) break;

        ll a0 = cc[A[i]];
        ll a1 = cc[A[i+M]];
        bit.add(a0, -1);
        bit.add(a1, 1);
        bit_sum.add(a0, -ccr[a0]);
        bit_sum.add(a1, ccr[a1]);
    }
    cout << endl;

}