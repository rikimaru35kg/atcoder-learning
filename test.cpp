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
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18;


struct UnionFind {
    vl p;
    ll num_union ;
    UnionFind(ll n) {
        p.resize(n, -1);
        num_union = n;
    }

    ll find (ll x) {
        if (p.at(x) == -1) return x;
        return p.at(x) = find(p.at(x));
    }

    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        p.at(x) = y;
        num_union--;
    }

    bool same(ll x, ll y) {
        if (find(x) == find(y)) return true;
        return false;
    }
};

struct Edge {
    ll a, b, cost;
    bool operator < (const Edge &e) {
        return cost < e.cost;
    }
};

int main () {
    ll N, M, K; cin >> N >> M >> K;
    vector<Edge> edges;
    rep (i, M) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        Edge e;
        e.a = a; e.b = b; e.cost = c;
        edges.push_back(e);
    }
    sort(all(edges));

    UnionFind uf(N);
    ll cost = 0;
    for (auto x: edges) {
        if (uf.num_union == K) break;
        if (uf.same(x.a, x.b)) continue;
        uf.unite(x.a, x.b);
        cost += x.cost;
    }

    cout << cost << endl;
}
