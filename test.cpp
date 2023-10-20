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

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
struct BIT {
    long long size;
    vector<long long> bit;
    BIT (long long _n): size(_n+1), bit(_n+1, 0) {}

    void add (long long i, long long x) {
        for (; i < size; i += (i & -i)) {
            bit[i] += x;
        }
    }

    long long sum (long long i) {
        long long ret = 0;
        for (; i > 0; i -= (i) & (-i)) {
            ret += bit[i];
        }
        return ret;
    }

    long long sum_lower_bound (long long k) {
        long long x = 0, len = 1;
        while ((len << 1) < size) len <<= 1;
        while(len > 0) {
            if (x + len < size && bit[x + len] < k) {
                k -= bit[x + len];
                x += len;
            }
            len >>= 1;
        }
        return x + 1;
    }

    void check_status () {
        for (long long i=1; i<size; ++i) {
            printf("%lld ", sum(i) - sum(i-1));
        }
        printf("\n");
    }
};

class CoordinateCompression {
    vector<long long> vec;
public:
    void add (long long x) {
        vec.push_back(x);
    }
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    long long get (long long x) {
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    }
    long long get_back (long long i) {
        if (i >= SIZE(vec)) return 3e18;
        return vec[i];
    }
    long long size () {
        return SIZE(vec);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LONG(N); VL(A, N);
    multiset<ll> st;
    st.insert(INF);
    rep (i, N) {
        auto it = st.lower_bound(A[i]);
        if (it == st.begin()) st.insert(A[i]);
        else {
            --it;
            st.insert(A[i]);
            st.erase(it);
        }
    }
    Out(SIZE(st)-1)
    // CoordinateCompression cc;
    // rep (i, N) cc.add(A[i]);
    // cc.compress();
    // ll M = cc.size();

    // BIT bit(M+1);
    // ll ans = 0;
    // rep (i, N) {
    //     ll a_comp = cc.get(A[i])+1;
    //     printf("%lld: ", i);
    //     bit.check_status();
    //     ans += bit.sum(M+1) - bit.sum(a_comp-1);
    //     bit.add(a_comp, 1);
    // }
    // Out(ans)
    
}

// ### test.cpp ###
