// ### test.cpp ###
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pr = pair<ll, ll>;
using Pd = pair<double, double>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector<Pr>;
using vpd = vector<Pd>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using vvp = vector<vector<Pr>>;
using vvb = vector<vector<bool>>;
using vvd = vector<vector<double>>;
using vvs = vector<vector<string>>;
using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<ll>>>;
using vvvb = vector<vector<vector<bool>>>;
using vvvd = vector<vector<vector<double>>>;
using t3 = tuple<ll,ll,ll>;
using t4 = tuple<ll,ll,ll,ll>;
using vt3 = vector<t3>;
using vt4 = vector<t4>;
using pq = priority_queue<Pr,vector<Pr>,greater<Pr>>;
using cl = complex<ll>;
using cd = complex<double>;
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
#define PYes {puts("Yes"); return 0;}
#define PNo {puts("No"); return 0;}
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INTM(...) int __VA_ARGS__; inm(__VA_ARGS__)
#define LONG(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define LONGM(...) ll __VA_ARGS__; inm(__VA_ARGS__)
#define DOUBLE(...) double __VA_ARGS__; in(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STRING(...) string __VA_ARGS__; in(__VA_ARGS__)
#define VI(ivec, n) vi ivec; input_ivec(ivec, n)
#define VIM(ivec, n) vi ivec; input_ivecm(ivec, n)
#define VL(lvec, n) vl lvec; input_lvec(lvec, n)
#define VLM(lvec, n) vl lvec; input_lvecm(lvec, n)
#define VS(svec, n) vs svec; input_svec(svec, n)
#define VD(dvec, n) vd dvec; input_dvec(dvec, n)
#define VP(pvec, n) vp pvec; input_pvec(pvec, n)
#define VPM(pvec, n) vp pvec; input_pvecm(pvec, n)
#define VVI(ivec2, h, w) vvi ivec2(h, vi(w)); input_ivec2(ivec2, h, w)
#define VVL(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2(lvec2, h, w)
#define VVLM(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2m(lvec2, h, w)
#define VVC(cvec2, h, w) vvc cvec2(h, vc(w)); input_cvec2(cvec2, h, w)
#define pcnt(x) __builtin_popcountll(x)
#define abs(x) llabs(x)
inline void Out(double x) {printf("%.10f",x);cout<<'\n';}
template<typename T> inline void Out(T x) {cout<<x<<'\n';}
template<typename T> inline void Out(vector<T> v) {rep(i,SIZE(v)) cout<<v[i]<<(i==SIZE(v)-1?'\n':' ');}
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
inline void mi(void) {return;}
template<typename T1, typename... T2> void mi(T1& f, T2&... r) {--f; mi(r...);}
template<class... T> void in(T&... x) {(cin >> ... >> x);}
template<class... T> void inm(T&... x) {(cin >> ... >> x); mi(x...);}
inline void input_ivec(vi &ivec, int n) {rep(i, n) {int x; cin >> x; ivec.push_back(x);}}
inline void input_ivecm(vi &ivec, int n) {rep(i, n) {int x; cin >> x; ivec.push_back(--x);}}
inline void input_lvec(vl &lvec, ll n) {rep(i, n) {ll x; cin >> x; lvec.push_back(x);}}
inline void input_lvecm(vl &lvec, ll n) {rep(i, n) {ll x; cin >> x; lvec.push_back(--x);}}
inline void input_svec(vs &svec, ll n) {rep (i, n) {string s; cin >> s; svec.push_back(s);}}
inline void input_dvec(vd &dvec, ll n) {rep (i, n) {double d; cin >> d; dvec.push_back(d);}}
inline void input_pvec(vp &pvec, ll n) {rep (i, n) {ll a, b; cin >> a >> b; pvec.emplace_back(a, b);}}
inline void input_pvecm(vp &pvec, ll n) {rep (i, n) {ll a, b; cin >> a >> b; pvec.emplace_back(--a, --b);}}
inline void input_ivec2(vvi &ivec2, int h, int w) {rep(i, h) rep(j, w) {int x; cin >> x; ivec2[i][j] = x;}}
inline void input_lvec2(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {ll x; cin >> x; lvec2[i][j] = x;}}
inline void input_lvec2m(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {ll x; cin >> x; lvec2[i][j] = --x;}}
inline void input_cvec2(vvc &cvec2, ll h, ll w) {rep(i, h) rep(j, w) {char c; cin >> c; cvec2[i][j] = c;}}
inline bool isin(ll i, ll j, ll h, ll w) {if(i<0||i>=h||j<0||j>=w) return false; else return true;}
inline ll Percent(ll a, ll b) {return (a%b+b)%b;}
inline ll Div(ll a, ll b) {return (a-Percent(a,b))/b; }
inline ll Divceil(ll a, ll b) {return Div(a+b-1, b); }
#ifdef __DEBUG
#define de(var) {cerr << #var << ": "; debug_view(var);}
template<typename T> inline void debug_view(T e){cerr << e << endl;}
template<typename T> inline void debug_view(pair<T,T> p){cerr << p.first << ' ' << p.second << endl;}
template<typename T> inline void debug_view(queue<T> q){while(!q.empty()) {cerr << q.front() << " "; q.pop();}cerr << endl;}
template<typename T> inline void debug_view(set<T> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(multiset<T> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(vector<pair<T,T>> &v){for(auto [a,b]: v){cerr<<"{"<<a<<" "<<b<<"} ";} cerr << endl;}
template<typename T> inline void debug_view(vector<T> &v){for(auto e: v){cerr << e << " ";} cerr << endl;}
template<typename T> inline void debug_view(vector<vector<pair<T,T>>> &vv){cerr << "----" << endl;for(auto &v: vv){debug_view(v);} cerr << "--------" << endl;}
template<typename T> inline void debug_view(vector<vector<T>> &vv){cerr << "----" << endl;for(auto &v: vv){debug_view(v);} cerr << "--------" << endl;}
template<typename T1,typename T2> inline void debug_view(map<T1,T2> &mp){cerr << "----" << endl;for(auto [k,v]: mp){cerr << k << ' ' << v << endl;} cerr << "--------" << endl;}
template<typename T1,typename T2> inline void debug_view(unordered_map<T1,T2> &mp){cerr << "----" << endl;for(auto [k,v]: mp){cerr << k << ' ' << v << endl;} cerr << "--------" << endl;}
template<typename T1,typename T2> inline void debug_view(map<T1,vector<T2>> &mp){cerr<<"----"<<endl;for(auto [k,v]: mp){cerr<<k<<": ";debug_view(v);} cerr << "--------" << endl;}
template<typename T1,typename T2,typename T3> inline void debug_view(map<pair<T1,T2>,T3> &mp){cerr << "----" << endl;for(auto [p,v]: mp){cerr<<'{'<<p.first<<' '<<p.second<<'}'<<": "<<v<<endl;} cerr<<"--------"<<endl;}
#define deb(var) {cerr << #var << ": "; debugb_view(var);}
template<typename T> inline void debugb_view(T e){bitset<20> b(e); cerr<<b<<endl;}
template<typename T> inline void debugb_view(vector<T> &v){cerr<<"----"<<endl;for(auto e: v){debugb_view(e);}}
#else
#define de(var) {}
#define deb(var) {}
#endif
const ll INF = 3e18;
template<typename T> inline void ch1(T &x){if(x==INF)x=-1;}
const double PI = acos(-1);
const double EPS = 1e-8;  //eg) if x=1e9, EPS >= 1e9/1e15(=1e-6)
const vi di = {0, 1, 0, -1};
const vi dj = {1, 0, -1, 0};
const vi di8 = {-1, -1, -1, 0, 0, 1, 1, 1};
const vi dj8 = {-1, 0, 1, -1, 1, -1, 0, 1};
Pr operator+ (Pr a, Pr b) {return {a.first+b.first, a.second+b.second};}
Pr operator- (Pr a, Pr b) {return {a.first-b.first, a.second-b.second};}
Pr operator* (Pr a, Pr b) {return {a.first*b.first, a.second*b.second};}
Pr operator/ (Pr a, Pr b) {return {a.first/b.first, a.second/b.second};}

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using vm = vector<mint>;
// using vvm = vector<vector<mint>>;
// using vvvm = vector<vector<vector<mint>>>;
// #ifdef __DEBUG
// inline void Out(vm v) {rep(i,SIZE(v)) cout << v[i].val() << (i==SIZE(v)-1?'\n':' ');}
// inline void debug_view(mint e){cerr << e.val() << endl;}
// inline void debug_view(vm &v){for(auto e: v){cerr << e.val() << " ";} cerr << endl;}
// inline void debug_view(vvm &vv){cerr << "----" << endl;for(auto &v: vv){debug_view(v);} cerr << "--------" << endl;}
// #endif

int main () {
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LONG(N, L, R);
    VL(A, N);
    int win = 0;
    rep(i, N) {
        ll x = A[i]%(L+R);
        ll y = x/L;
        win ^= y;
    }
    if (win) puts("First");
    else puts("Second");
    
}

// ### test.cpp ###
