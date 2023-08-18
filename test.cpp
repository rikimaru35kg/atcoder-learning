#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define ql queue<ll>
#define dql deque<ll>
#define pql priority_queue<ll>
#define pqla priority_queue<ll,vl,greater<ll>>
#define mll map<ll, ll>
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

template <typename T>
struct UnionFind {
    vector<T> p, num;
    vector<bool> con;
    UnionFind(T n) : p(n, -1), num(n, 1), con(n, false) {}

    void connect(T x) {
        con[x] = true;
    }

    T find (T x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    void unite (T x, T y) {
        x = find(x); y = find(y);
        if (x == y) return;
        p[x] = y;
        num[y] += num[x];
        if (con[x] | con[y]) con[y] = true;
    }
    bool same (T x, T y) {
        return find(x) == find(y);
    }
    T size (T x) {
        return num[find(x)];
    }
    bool conjudge (T x) {
        return con[find(x)];
    }
};


int main () {
    ll N, M, E; cin >> N >> M >> E;
    vp edges(E);
    rep (i, E) cin >> edges[i].first >> edges[i].second;
    rep (i, E) {--edges[i].first; --edges[i].second;}
    ll Q; cin >> Q;
    unordered_set<int> X;
    vl Xv(Q);
    rep (i, Q) {
        int x; cin >> x; --x;
        X.insert(x);
        Xv[i] = x;
    }

    // vb connected(N+M);
    UnionFind<ll> uf(N+M);
    repk (i, N, N+M) uf.connect(i);

    ll cnt = 0;
    rep (i, E) {
        auto [a, b] = edges[i];
        if (!X.count(i)) {
            if (uf.conjudge(a) || uf.conjudge(b)) {
                if (!uf.conjudge(a)) cnt += uf.size(a);
                if (!uf.conjudge(b)) cnt += uf.size(b);
            }
            uf.unite(a, b);
        }
    }

    vl ansvec(Q);
    repr (xi, Q) {
        ansvec[xi] = cnt;
        auto [a, b] = edges[Xv[xi]];
        if (uf.conjudge(a) || uf.conjudge(b)) {
            if (!uf.conjudge(a)) cnt += uf.size(a);
            if (!uf.conjudge(b)) cnt += uf.size(b);
        }
        uf.unite(a, b);
    }

    rep (i, Q) cout << ansvec[i] << endl;
 

}