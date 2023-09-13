// ### test.cpp ###
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
template<class... T> void in(T&... x) {(cin >> ... >> x);}
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;


int main () {
    ll N; in(N);
    vl r(N), c(N), x(N);
    rep (i, N) in(r[i], c[i], x[i]);

    map<ll,ll> cols, rows;
    map<ll,vl> cs;
    map<Pair,ll> a;
    rep (i, N) {
        rows[r[i]] += x[i];
        cols[c[i]] += x[i];
        cs[r[i]].push_back(c[i]);
        a[{r[i], c[i]}] += x[i];
    }
    multiset<ll> ts;
    for (auto [k, v]: cols) ts.insert(v);
    ts.insert(-1);

    ll ans = 0;
    for (auto [k, v]: rows) {
        for (auto col: cs[k]) {
            ts.erase(ts.find(cols[col]));
            chmax(ans, v + cols[col] - a[{k, col}]);
        }
        ll tmax = *ts.rbegin();
        chmax(ans, v + tmax);
        for (auto col: cs[k]) {
            ts.insert(cols[col]);
        }
    }

    Out(ans)



}

// ### test.cpp ###
