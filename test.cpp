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
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INTM(...) int __VA_ARGS__; inm(__VA_ARGS__)
#define LONG(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define LONGM(...) ll __VA_ARGS__; inm(__VA_ARGS__)
#define STRING(...) string __VA_ARGS__; in(__VA_ARGS__)
#define VL(lvec, n) vl lvec; input_lvec(lvec, n)
#define VS(svec, n) vs svec; input_svec(svec, n)
#define VVC(cvec, h, w) vvc cvec(h, vc(w)); input_cvec(cvec, h, w)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
inline void mi(void) {return;}
template<typename T1, typename... T2> void mi(T1& f, T2&... r) {--f; mi(r...);}
template<class... T> void in(T&... x) {(cin >> ... >> x);}
template<class... T> void inm(T&... x) {(cin >> ... >> x); mi(x...);}
inline void input_lvec(vl &lvec, ll n) {rep(i, n) {ll x; cin >> x; lvec.push_back(x);}}
inline void input_svec(vs &svec, ll n) {rep (i, n) {string s; cin >> s; svec.push_back(s);}}
inline void input_cvec(vvc &cvec, ll h, ll w) {rep(i, h) rep(j, w) {char c; cin >> c; cvec[i][j] = c;}}
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;


int main () {
    LONG(N);
    

}

// ### test.cpp ###
