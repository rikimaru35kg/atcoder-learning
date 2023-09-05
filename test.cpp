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


int main () {
    ll N; cin >> N;
    vs S(N), T(N);
    rep (i, N) cin >> S[i] >> T[i];

    map<string,ll> mp;
    rep (i, N) mp[S[i]] = 0;
    rep (i, N) mp[T[i]] = 0;
    ll idx = 0;
    for (auto [k, v]: mp) {
        mp[k] = idx;
        ++idx;
    }
    ll M = SIZE(mp);
    vl to(M, -1);
    rep (i, N) {
        ll u = mp[S[i]];
        ll v = mp[T[i]];
        to[u] = v;
    }

    vb used(M);
    vb finished(M);
    auto judge_cycle = [&](auto f, ll x) -> bool {
        used[x] = true;
        if (to[x] != -1) {
            if (!finished[to[x]]) {
                if (used[to[x]]) return true;
                if (f(f, to[x])) return true;
            }
        }
        finished[x] = true;
        return false;
    };

    rep (i, M) {
        if (used[i]) continue;
        if (judge_cycle(judge_cycle, i)) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
}