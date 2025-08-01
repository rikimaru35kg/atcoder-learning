// ### test.cpp ###
#include <bits/stdc++.h>
#ifdef __DEBUG_VECTOR
namespace for_debugging{
    struct subscript_and_location{
        int sub;
        std::source_location loc;
        subscript_and_location(int sub_,std::source_location loc_=std::source_location::current()){
            sub=sub_;
            loc=loc_;
        }
        void check_out_of_range(size_t sz){
            if(sub<0||(int)sz<=sub){
                std::clog << loc.file_name() << ":(" << loc.line() << ":" << loc.column() << "):" << loc.function_name() << std::endl;
                std::clog << "out of range: subscript = " << sub << ", vector_size = " << sz << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    };
}
namespace std{
    template<class T,class Allocator=std::allocator<T>> class vector_for_debugging:public std::vector<T,Allocator>{
        using std::vector<T,Allocator>::vector;
        public:
            [[nodiscard]] constexpr std::vector<T,Allocator>::reference operator[](for_debugging::subscript_and_location n) noexcept(!std::is_same<T,bool>::value){
                n.check_out_of_range(this->size());
                return std::vector<T,Allocator>::operator[](n.sub);
            }
            [[nodiscard]] constexpr std::vector<T,Allocator>::const_reference operator[](for_debugging::subscript_and_location n) const noexcept(!std::is_same<T,bool>::value){
                n.check_out_of_range(this->size());
                return std::vector<T,Allocator>::operator[](n.sub);
            }
    };
    namespace pmr{
        template<class T> using vector_for_debugging=std::vector_for_debugging<T,std::pmr::polymorphic_allocator<T>>;
    }
}
#define vector vector_for_debugging
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using sll = __int128_t;
using db = double;
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
istream& operator>>(istream &is, t3 &t) { is>>get<0>(t)>>get<1>(t)>>get<2>(t); return is; }
ostream& operator<<(ostream& os, const t3& t) { os<<"("<<get<0>(t)<<','<<get<1>(t)<<','<<get<2>(t)<<")"; return os; }
using t3d = tuple<db,db,db>;
using t4 = tuple<ll,ll,ll,ll>;
istream& operator>>(istream &is, t4 &t) { is>>get<0>(t)>>get<1>(t)>>get<2>(t)>>get<3>(t); return is; }
ostream& operator<<(ostream& os, const t4& t) { os<<"("<<get<0>(t)<<','<<get<1>(t)<<','<<get<2>(t)<<','<<get<3>(t)<<")"; return os; }
using vt3 = vector<t3>;
using vt3d = vector<t3d>;
using vt4 = vector<t4>;
using vvt3 = vector<vector<t3>>;
using vvt3d = vector<vector<t3d>>;
using vvt4 = vector<vector<t4>>;
using pq = priority_queue<Pr,vector<Pr>,greater<Pr>>;
using cl = complex<ll>;
using cd = complex<double>;
#define rep(i, N) for (ll i=0; i<(ll)(N); ++i)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; --i)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); ++i)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); ++i)
#define rep1r(i, N) for (ll i=(ll)(N); i>0; i--)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
#define PYes {puts("Yes"); exit(0);}
#define PNo {puts("No"); exit(0);}
#define PFi {puts("First"); exit(0);}
#define PSe {puts("Second"); exit(0);}
#define Pm0 {puts("0"); exit(0);}
#define Pm1 {puts("-1"); exit(0);}
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define INTM(...) int __VA_ARGS__; inm(__VA_ARGS__)
#define LONG(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define LONGM(...) ll __VA_ARGS__; inm(__VA_ARGS__)
#define DOUBLE(...) double __VA_ARGS__; in(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define STRING(...) string __VA_ARGS__; in(__VA_ARGS__)
#define VI(ivec, n) vi ivec(n); input_ivec(ivec, n)
#define VIM(ivec, n) vi ivec(n); input_ivecm(ivec, n)
#define VL(lvec, n) vl lvec(n); input_lvec(lvec, n)
#define VLM(lvec, n) vl lvec(n); input_lvecm(lvec, n)
#define VL2(lvec1, lvec2, n) vl lvec1(n), lvec2(n); input_lvec12(lvec1, lvec2, n)
#define VL2M(lvec1, lvec2, n) vl lvec1(n), lvec2(n); input_lvec12m(lvec1, lvec2, n)
#define VC(cvec, n) vc cvec(n); input_cvec(cvec, n)
#define VS(svec, n) vs svec(n); input_svec(svec, n)
#define VD(dvec, n) vd dvec(n); input_dvec(dvec, n)
#define VP(pvec, n) vp pvec(n); input_pvec(pvec, n)
#define VPD(pvec, n) vpd pvec(n); input_pvecd(pvec, n)
#define VPM(pvec, n) vp pvec(n); input_pvecm(pvec, n)
#define VVI(ivec2, h, w) vvi ivec2(h, vi(w)); input_ivec2(ivec2, h, w)
#define VVL(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2(lvec2, h, w)
#define VVLM(lvec2, h, w) vvl lvec2(h, vl(w)); input_lvec2m(lvec2, h, w)
#define VVC(cvec2, h, w) vvc cvec2(h, vc(w)); input_cvec2(cvec2, h, w)
#define uset unordered_set
#define umap unordered_map
inline int pcnt(ll s, ll n=-1) { // n!=-1 for # of 0
    if(n==-1) return __builtin_popcountll(s);
    return n-__builtin_popcountll(s);
}
inline int parity(ll s, ll n=-1) { // n!=-1 for # of 0
    if(n==-1) return __builtin_parityll(s);
    return (n-__builtin_popcountll(s))%2;
}
inline void Out(double x) {printf("%.15f",x);cout<<'\n';}
template<typename T> inline void Out(pair<T,T> x) {cout<<x.first<<' '<<x.second<<'\n';}
template<typename T> inline void Out(T x) {cout<<x<<'\n';}
inline void Out(vector<string> v) {rep(i,SIZE(v)) cout<<v[i]<<'\n';}
template<typename T> inline void Out(queue<T> q){while(!q.empty()) {cout<<q.front()<<" "; q.pop();} cout<<endl;}
template<typename T> inline void Out(deque<T> q){while(!q.empty()) {cout<<q.front()<<" "; q.pop_front();} cout<<endl;}
template<typename T> inline void Out(vector<T> v) {rep(i,SIZE(v)) cout<<v[i]<<(i==SIZE(v)-1?'\n':' ');}
template<typename T> inline void Out(vector<vector<T>> &vv){for(auto &v: vv) Out(v);}
template<typename T> inline void Out(vector<pair<T,T>> v) {for(auto p:v) Out(p);}
template<typename T> inline void Outend(T x) {Out(x); exit(0);}
template<typename T> inline void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline void chmax(T &a, T b) { a = max(a, b); }
inline void mi(void) {return;}
template<typename T1, typename... T2> void mi(T1& f, T2&... r) {--f; mi(r...);}
template<class... T> void in(T&... x) {(cin >> ... >> x);}
template<class... T> void inm(T&... x) {(cin >> ... >> x); mi(x...);}
inline void input_ivec(vi &ivec, int n) {rep(i, n) {cin>>ivec[i];}}
inline void input_ivecm(vi &ivec, int n) {rep(i, n) {cin>>ivec[i];--ivec[i];}}
inline void input_lvec(vl &lvec, ll n) {rep(i, n) {cin>>lvec[i];}}
inline void input_lvecm(vl &lvec, ll n) {rep(i, n) {cin>>lvec[i];--lvec[i];}}
inline void input_lvec12(vl &lvec1, vl &lvec2, ll n) {rep(i, n) {cin>>lvec1[i]>>lvec2[i];}}
inline void input_lvec12m(vl &lvec1, vl &lvec2, ll n) {rep(i, n) {cin>>lvec1[i]>>lvec2[i];--lvec1[i];--lvec2[i];}}
inline void input_cvec(vc &cvec, ll n) {rep (i, n) {cin>>cvec[i];}}
inline void input_svec(vs &svec, ll n) {rep (i, n) {cin>>svec[i];}}
inline void input_dvec(vd &dvec, ll n) {rep (i, n) {cin>>dvec[i];}}
inline void input_pvec(vp &pvec, ll n) {rep (i, n) {cin>>pvec[i].first>>pvec[i].second;}}
inline void input_pvecm(vp &pvec, ll n) {rep (i, n) {cin>>pvec[i].first>>pvec[i].second;pvec[i].first--,pvec[i].second--;}}
inline void input_pvecd(vpd &pvec, ll n) {rep (i, n) {cin>>pvec[i].first>>pvec[i].second;}}
inline void input_ivec2(vvi &ivec2, int h, int w) {rep(i, h) rep(j, w) {cin>>ivec2[i][j];}}
inline void input_lvec2(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {cin>>lvec2[i][j];}}
inline void input_lvec2m(vvl &lvec2, ll h, ll w) {rep(i, h) rep(j, w) {cin>>lvec2[i][j];--lvec2[i][j];}}
inline void input_cvec2(vvc &cvec2, ll h, ll w) {rep(i, h) rep(j, w) {cin>>cvec2[i][j];}}
inline bool isin(ll i, ll j, ll h, ll w) {if(i<0||i>=h||j<0||j>=w) return false; else return true;}
template<typename T> inline T TmpPercent(T a, T b) {if(b<0){a=-a,b=-b;} return (a%b+b)%b;}
template<typename T> inline T Percent(T a, T b) {if(b<0) return -TmpPercent(a,b); return TmpPercent(a,b);}
template<typename T> inline T Div(T a, T b) {if(b<0){a=-a,b=-b;} return (a-TmpPercent(a,b))/b; }
template<typename T> inline T Divceil(T a, T b) {if(TmpPercent(a,b)==0) return Div(a,b); return Div(a,b)+1;}
template<typename T> void erase(multiset<T> &st, T x) {if(st.contains(x)) st.erase(st.find(x));}
template<typename T> T pop(vector<T> &x) {T ret=x.back(); x.pop_back(); return ret;}
template<typename T> inline void sort3(T &a,T &b,T &c) {if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);}
#ifdef __DEBUG
#define de(var) {cerr << #var << ": "; debug_view(var);}
#define de2(var1,var2) {cerr<<#var1<<' '<<#var2<<": "; debug_view(var1,var2);}
#define de3(var1,var2,var3) {cerr<<#var1<<' '<<#var2<<' '<<#var3<<": "; debug_view(var1,var2,var3);}
#define de4(var1,var2,var3,var4) {cerr<<#var1<<' '<<#var2<<' '<<#var3<<' '<<#var4<<": "; debug_view(var1,var2,var3,var4);}
#define de5(var1,var2,var3,var4,var5) {cerr<<#var1<<' '<<#var2<<' '<<#var3<<' '<<#var4<<' '<<#var5<<": "; debug_view(var1,var2,var3,var4,var5);}
template<typename T> inline void debug_view(T e){cerr << e << endl;}
template<typename T1, typename T2> inline void debug_view(T1 e1, T2 e2){cerr<<e1<<' '<<e2<<endl;}
template<typename T1, typename T2, typename T3> inline void debug_view(T1 e1, T2 e2, T3 e3){cerr<<e1<<' '<<e2<<' '<<e3<<endl;}
template<typename T1, typename T2, typename T3, typename T4> inline void debug_view(T1 e1, T2 e2, T3 e3, T4 e4){cerr<<e1<<' '<<e2<<' '<<e3<<' '<<e4<<endl;}
template<typename T1, typename T2, typename T3, typename T4, typename T5> inline void debug_view(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5){cerr<<e1<<' '<<e2<<' '<<e3<<' '<<e4<<' '<<e5<<endl;}
template<typename T1, typename T2> inline void debug_view(pair<T1,T2> &p){cerr<<"{"<<p.first<<" "<<p.second<<"}\n";}
template<typename T1, typename T2> inline void debug_view(vector<pair<T1,T2>> &v){for(auto [a,b]: v){cerr<<"{"<<a<<" "<<b<<"} ";} cerr << endl;}
template<typename T1, typename T2> inline void debug_view(set<pair<T1,T2>> &s){for(auto [a,b]: s){cerr<<"{"<<a<<" "<<b<<"} ";} cerr << endl;}
template<typename T> inline void debug_view(tuple<T,T,T> t){cerr<<get<0>(t)<<' '<<get<1>(t)<<' '<<get<2>(t)<< endl;}
template<typename T> inline void debug_view(queue<T> q){while(!q.empty()) {cerr << q.front() << " "; q.pop();}cerr << endl;}
template<typename T> inline void debug_view(deque<T> q){while(!q.empty()) {cerr << q.front() << " "; q.pop_front();}cerr << endl;}
template<typename T> inline void debug_view(set<T> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(set<T,greater<T>> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(unordered_set<T> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(multiset<T> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(multiset<T,greater<T>> s){for(auto x:s){cerr << x << ' ';}cerr << endl;}
template<typename T> inline void debug_view(vector<pair<T,T>> &v){for(auto [a,b]: v){cerr<<"{"<<a<<" "<<b<<"} ";} cerr << endl;}
inline void debug_view(vector<string> &v){cerr << "----" << endl; for(auto s: v) debug_view(s);}
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
#define de2(var1,var2) {}
#define de3(var1,var2,var3) {}
#define de4(var1,var2,var3,var4) {}
#define de5(var1,var2,var3,var4,var5) {}
#define deb(var) {}
#endif
int IINF = 1001001001;
ll INF = 3e18;
const ll M998 = 998244353;
const ll M107 = 1000000007;
template<typename T> inline void ch1(T &x){if(x==INF)x=-1;}
const double PI = acos(-1);
const double EPS = 1e-8;  //eg) if x=1e6, EPS >= 1e6/1e14(=1e-8)
const vi di = {0, 1, 0, -1};
const vi dj = {1, 0, -1, 0};
const vp dij = {{0,1},{1,0},{0,-1},{-1,0}};
const vp hex0 = {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}}; // tobide
const vp hex1 = {{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}};  // hekomi
const vi di8 = {-1, -1, -1, 0, 0, 1, 1, 1};
const vi dj8 = {-1, 0, 1, -1, 1, -1, 0, 1};
const vp dij8 = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
Pr operator+ (Pr a, Pr b) {return {a.first+b.first, a.second+b.second};}
Pr operator- (Pr a, Pr b) {return {a.first-b.first, a.second-b.second};}
Pr operator* (Pr a, Pr b) {return {a.first*b.first, a.second*b.second};}
Pr operator/ (Pr a, Pr b) {return {a.first/b.first, a.second/b.second};}

class MaxFlow {
    int n;
    vector<int> dist, iter;
    long long inf = numeric_limits<long long>::max();
    struct Edge {
        int to; long long cap; int rev;
        Edge(int to, long long cap, int rev): to(to), cap(cap), rev(rev) {}
    };
    void bfs(int sv) {
        dist.assign(n, -1);
        queue<int> que;
        dist[sv] = 0; que.push(sv);
        while(que.size()) {
            auto v = que.front(); que.pop();
            for(auto [nv,cap,rev]: from[v]) {
                if(cap==0 || dist[nv]!=-1) continue;
                dist[nv] = dist[v]+1, que.push(nv); 
            }
        }
    }
    long long dfs(int v, int t, long long f) {
        if(v==t) return f;
        for(int &i=iter[v]; i<int(from[v].size()); i++) {
            auto [nv,cap,rev] = from[v][i];
            if(dist[nv]<=dist[v] || cap==0) continue;
            long long res = dfs(nv, t, min(f,cap));
            if(res) {
                from[v][i].cap -= res;
                from[nv][rev].cap += res;
                return res;
            }
        }
        return 0;
    }
public:
    vector<vector<Edge>> from;
    MaxFlow(int n): n(n), from(n) {}
    void add_edge(int a, int b, long long c) {
        from[a].emplace_back(Edge(b,c,from[b].size()));
        from[b].emplace_back(Edge(a,0,from[a].size()-1));
    }
    long long flow(int s, int t) {
        long long ret = 0;
        while(true) {
            bfs(s);
            if(dist[t]==-1) return ret;
            iter.assign(n, 0);
            long long now=0;
            while((now=dfs(s,t,inf))>0) {
                ret += now;
            }
        }
        return 0;
    }
};

//! Calculate Euclid distance
//! input type = double
//! output type = double
double euclid_distd(pair<double,double> p1, pair<double,double> p2) {
    double ret = 0;
    ret += (p1.first - p2.first) * (p1.first - p2.first);
    ret += (p1.second - p2.second) * (p1.second - p2.second);
    ret = sqrt(ret);
    return ret;
}

long long binary_search (long long ok, long long ng, auto f) {
    while (llabs(ok-ng) > 1) {
        ll l = min(ok, ng), r = max(ok, ng);
        long long m = l + (r-l)/2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}
//! For DOUBLE TYPE, PLEASE CAST THE TYPE OF INPUTS TO DOUBLE
//! TO CORRECTLY INFER THE PROPER FUNCTION!!
double binary_search (double ok, double ng, auto f) {
    const int REPEAT = 100;
    for(int i=0; i<=REPEAT; ++i) {
        double m = (ok + ng) / 2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}

void solve() {
    LONG(N);
    VP(S, N);
    VP(G, N);
    
    vd ds;
    rep(i, N) rep(j, N) {
        ds.push_back(euclid_distd(S[i], G[j]));
    }
    sort(all(ds));

    auto f = [&](ll di) -> bool {
        db d = ds[di];
        MaxFlow flow(2*N+2);
        ll s = 2*N, g = s+1;
        rep(i, N) rep(j, N) {
            db cd = euclid_distd(S[i], G[j]);
            if (cd <= d) flow.add_edge(i, N+j, 1);
        }
        rep(i, N) flow.add_edge(s, i, 1);
        repk(i, N, 2*N) flow.add_edge(i, g, 1);

        ll mxf = flow.flow(s, g);
        return mxf >= N;
    };

    ll ansi = binary_search(N*N, -1, f);
    Out(ds[ansi]);


}

int main () {
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

// ### test.cpp ###
