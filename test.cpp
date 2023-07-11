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
#define ql queue<ll>
#define dql deque<ll>
#define pql priority_queue<ll>
#define pqla priority_queue<ll,vl,greater<ll>>
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

template <typename T>
struct UnionFind {
    vector<T> p;
    UnionFind(T n) : p(n, -1) {}

    T find (T x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    void unite (T x, T y) {
        x = find(x); y = find(y);
        if (x == y) return;
        p[x] = y;
    }
    bool same (T x, T y) {
        return find(x) == find(y);
    }
};

int main () {
    ll N, M; cin >> N >> M;
    vvl from(N);
    vp edges(M);
    rep (i, M) {
        ll a, b; cin >> a >> b; --a; --b;
        from[a].push_back(b);
        from[b].push_back(a);
        edges[i] = {a, b};
    }

    vl deg(N, 0);
    UnionFind<ll> uf(N);
    for (auto [a, b] : edges) {
        ++deg[a]; ++deg[b];
        if (uf.same(a, b)) {
            cout << "No" << endl;
            return 0;
        }
        uf.unite(a, b);
    }
    ll mx = 0;
    rep (i, N) {
        chmax(mx, deg[i]);
    }
    if (mx > 2) {
        cout << "No" << endl;
        return 0;
    }


    cout << "Yes" << endl;
    return 0;
}

