#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = pair<ll, ll>;
using Paird = pair<double, double>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector<Pair>;
using vpd = vector<Paird>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvd = vector<vector<double>>;
using vvs = vector<vector<string>>;
using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<ll>>>;
using vvvb = vector<vector<vector<bool>>>;
using vvvd = vector<vector<vector<double>>>;
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
#define Out(x) cout << (x) << endl;
#define print_vec(vec) {for (auto x: vec) cout << x << ' '; cout << endl;}
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;

int solve() {
    ll N, M; cin >> N >> M;
    vi C(N);
    rep (i, N) cin >> C[i];
    vvi from(N);
    rep (i, M) {
        ll u, v; cin >> u >> v;
        --u; --v;
        from[u].push_back(v);
        from[v].push_back(u);
    }

    vvl dist(N, vl(N, INF));
    dist[0][N-1] = 0;
    queue<Pair> que;
    que.emplace(0, N-1);
    while (!que.empty()) {
        auto [t, a] = que.front(); que.pop();
        for (auto nt: from[t]) for (auto na: from[a]) {
            if (C[nt] == C[na]) continue;
            if (dist[nt][na] != INF) continue;
            dist[nt][na] = dist[t][a] + 1;
            que.emplace(nt, na);
        }
    }

    if (dist[N-1][0] == INF) Pdame
    Out(dist[N-1][0]);
    return 0;
}


int main () {
    ll T; cin >> T;
    rep (i, T) {
        solve();
    }
}
