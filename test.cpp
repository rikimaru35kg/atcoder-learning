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
using vvp = vector<vector<Pair>>;
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
#define Out(x) {cout << (x) << endl;}
#define print_vec(vec) {rep (iii, SIZE(vec)) {if(iii==SIZE(vec)-1) cout << vec[iii] << '\n'; else cout << vec[iii] << ' ';}}
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INTM(...) int __VA_ARGS__; inm(__VA_ARGS__)
#define LONG(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define LONGM(...) ll __VA_ARGS__; inm(__VA_ARGS__)
#define DOUBLE(...) double __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STRING(...) string __VA_ARGS__; in(__VA_ARGS__)
#define VL(lvec, n) vl lvec; input_lvec(lvec, n)
#define VLM(lvec, n) vl lvec; input_lvecm(lvec, n)
#define VS(svec, n) vs svec; input_svec(svec, n)
#define VP(pvec, n) vp pvec; input_pvec(pvec, n)
#define VPM(pvec, n) vp pvec; input_pvecm(pvec, n)
#define VVL(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2(lvec2, h, w)
#define VVLM(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2m(lvec2, h, w)
#define VVC(cvec2, h, w) vvc cvec2(h, vc(w)); input_cvec2(cvec2, h, w)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
inline void mi(void) {return;}
template<typename T1, typename... T2> void mi(T1& f, T2&... r) {--f; mi(r...);}
template<class... T> void in(T&... x) {(cin >> ... >> x);}
template<class... T> void inm(T&... x) {(cin >> ... >> x); mi(x...);}
inline void input_lvec(vl &lvec, ll n) {rep(i, n) {ll x; cin >> x; lvec.push_back(x);}}
inline void input_lvecm(vl &lvec, ll n) {rep(i, n) {ll x; cin >> x; lvec.push_back(--x);}}
inline void input_svec(vs &svec, ll n) {rep (i, n) {string s; cin >> s; svec.push_back(s);}}
inline void input_pvec(vp &pvec, ll n) {rep (i, n) {ll a, b; cin >> a >> b; pvec.emplace_back(a, b);}}
inline void input_pvecm(vp &pvec, ll n) {rep (i, n) {ll a, b; cin >> a >> b; pvec.emplace_back(--a, --b);}}
inline void input_lvec2(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {ll x; cin >> x; lvec2[i][j] = x;}}
inline void input_lvec2m(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {ll x; cin >> x; lvec2[i][j] = --x;}}
inline void input_cvec2(vvc &cvec2, ll h, ll w) {rep(i, h) rep(j, w) {char c; cin >> c; cvec2[i][j] = c;}}
#ifdef __DEBUG
#define debug(var) {cerr << #var << ": "; debug_view(var);}
inline void debug_view(Pair &p){cerr << p.first << ' ' << p.second << endl;}
inline void debug_view(ll &e){cerr << e << endl;}
template<typename T> inline void debug_view(const vector<T> &v){for(const auto &e: v){cerr << e << " ";} cerr << endl;}
template<typename T> inline void debug_view(const vector<vector<T>> &vv){cerr << "----" << endl;for(const auto &v: vv){debug_view(v);} cerr << "--------" << endl;}
template<typename T1,typename T2> inline void debug_view(const map<T1,T2> &mp){cerr << "----" << endl;for(auto [k,v]: mp){cerr << k << ' ' << v << endl;} cerr << "--------" << endl;}
#else
#define debug(var)
#endif
const ll INF = 3e18;
const double PI = acos(-1);
const double EPS = 1e-8;  //eg) if x=1e9, EPS >= 1e9/1e15(=1e-6)

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
//! eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
//! primes = {(1,1), (2,3), (3,2), (5,1)}
//! NOTE: 1^1 is always included!!
vector<pair<long long, long long>> prime_factrization (long long n) {
    vector<pair<long long, long long>> primes;
    primes.emplace_back(1, 1);
    for (long long k=2; k*k<=n; ++k) {
        if (n % k != 0) continue;
        primes.emplace_back(k, 0);
        while(n % k == 0) {
            n /= k;
            primes.back().second++;
        }
    }
    if (n != 1) primes.emplace_back(n, 1);
    return primes;
}
class Sieve {
    long long n;
    vector<long long> sieve;
    void add_prime(vector<pair<long long,long long>> &vp, long long m) {
        if (vp.size() == 0) {
            vp.emplace_back(m, 1);
            return;
        }
        if (vp.back().first == m) {
            ++vp.back().second;
        } else {
            vp.emplace_back(m, 1);
        }
    }
public:
    Sieve (long long n): n(n), sieve(n+1) {
        for (long long i=2; i<=n; ++i) {
            if (sieve[i] != 0) continue;
            for (long long k=i*i; k<=n; k+=i) {
                if (sieve[k] == 0) sieve[k] = i;
            }
        }
    }
    bool is_prime(long long k) {
        if (k <= 1 || k > n) return false;
        if (sieve[k] == 0) return true;
        return false;
    }
    vector<pair<long long,long long>> factorize(long long k) {
        vector<pair<long long,long long>> ret;
        if (k <= 1 || k > n) return ret;
        while (sieve[k] != 0) {
            add_prime(ret, sieve[k]);
            k /= sieve[k];
        }
        add_prime(ret, k);
        return ret;
    }
};
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LONG(N);
    VL(A, N);
    map<ll,ll> mp;
    Sieve sieve((ll)1e6);
    rep (i, N) {
        vp vecp = sieve.factorize(A[i]);
        for (auto [k, v]: vecp) {
            chmax(mp[k], v);
        }
    }
    mint l = 1;
    for (auto [k, v]: mp) {
        rep (j, v) l *= k;
    }
    mint ans = 0;
    rep (i, N ) {
        ans += l / A[i];
    }
    Out(ans.val())
}

// ### test.cpp ###
