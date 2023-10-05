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
#define Out(x) cout << (x) << endl;
#define print_vec(vec) {rep (iii, SIZE(vec)) {if(iii==SIZE(vec)-1) cout << vec[iii] << '\n'; else cout << vec[iii] << ' ';}}
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INTM(...) int __VA_ARGS__; inm(__VA_ARGS__)
#define LONG(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define LONGM(...) ll __VA_ARGS__; inm(__VA_ARGS__)
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
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

vector<pair<long long, long long>> prime_factrization (long long n) {
    // eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
    // primes = {(1,1), (2,3), (3,2), (5,1)}
    // NOTE: 1^1 is always included!!
    vector<pair<long long, long long>> primes;
    primes.emplace_back(1, 1);
    long long rem = n;
    for (long long k=2; k*k<=n; ++k) {
        long long num = 0;
        while(rem % k == 0) {
            ++num;
            rem /= k;
        }
        if (num > 0) primes.emplace_back(k, num);
    }
    if (rem != 1) primes.emplace_back(rem, 1);
    return primes;
}

// Calculate mod(a^b, mod)
// a >= 0, b >= 0, mod > 0;
long long modpow(long long a, long long b, long long mod) {
	long long ans = 1;
	a %= mod;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}

//! Calculate factorias from 0 to n.
//! Specify empty vector as facts.
void stock_factorials (vector<long long> &facts, long long n, long long mod) {
    long long x = 1;
    for (long long i=0; i<=n; ++i) {
        (x *= max(1LL, i)) %= mod;
        facts.push_back(x);
    }
}

//! Calculate nCr based on factorias vector.
//! Please put modpow funtion above.
long long nCr_based_on_factorials(long long n, long long r, vector<long long> &facts, long long mod) {
    long long ret = 1;
    (ret *= facts[n]) %= mod;
    long long r_inv = modpow(facts[r], mod-2, mod);
    long long nr_inv = modpow(facts[n-r], mod-2, mod);
    (ret *= r_inv) %= mod;
    (ret *= nr_inv) %= mod;
    return ret;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LONG(N, M);
    ll MOD = 1e9+7;

    vp primes = prime_factrization(M);
    vl pnums;
    for (auto [a, b]: primes) {
        if (a != 1) pnums.push_back(b);
    }
    ll mx = -1;
    for (auto x: pnums) chmax(mx, x);

    vl facts;
    stock_factorials(facts, mx+N-1, MOD);
    mint ans = 1;
    rep (i, SIZE(pnums)) {
        ll r = pnums[i];
        ans *= nCr_based_on_factorials(r+N-1, N-1, facts, MOD);
    }
    Out(ans.val())

    
}

// ### test.cpp ###
