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
#define vvs vector<vector<string>>
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
#define PYes {puts("Yes"); return 0;}
#define PNo {puts("No"); return 0;}
#define Pdame {puts("-1"); return 0;}
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;


int main () {
    ll N; cin >> N;
    vl A(N); rep (i, N) cin >> A[i];
    vs S(N); rep (i, N) cin >> S[i];

    ll Q; cin >> Q;
    vp paths(Q);
    rep (i, Q) {
        ll u, v; cin >> u >> v;
        --u; --v;
        paths[i] = {u, v};
    }

    vvl dist(N, vl(N, INF));
    rep (i, N) rep (j, N) {
        if (i == j) dist[i][j] = 0;
        if (S[i][j] == 'Y') dist[i][j] = (ll)1e15 - A[j];
    }

    rep (k, N) rep (i, N) rep (j, N) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    rep (i, Q) {
        auto [u, v] = paths[i];
        ll d = dist[u][v];
        ll n = d / (ll)1e15;
        ll val = (-d % (ll)1e15 + (ll)1e15) + A[u];
        if (d == INF) puts("Impossible");
        else printf("%lld %lld\n", n+1, val);
    }


}
