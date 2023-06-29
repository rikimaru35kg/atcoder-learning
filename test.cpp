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
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;
const ll MOD = 1e9 + 7;

struct UnionFind {
    vl p, num;
    UnionFind (ll n) {
        p.resize(n, -1);
        num.resize(n, 1);
    }

    ll find (ll x) {
        if (p.at(x) == -1) return x;
        return p.at(x) = find(p.at(x));
    }

    void unite (ll x, ll y) {
        x = find(x); y = find(y);
        if (x == y) return;
        p.at(x) = y;
        num.at(y) += num.at(x);
    }

    ll size_i (ll x) {
        x = find(x);
        return num.at(x);
    }
};


int main () {
    ll N; cin >> N;
    vector<tuple<ll,ll,ll>> edges;
    rep (i, N-1) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, u, v);
    }

    ll total = 0;
    UnionFind uf(N);
    sort(all(edges));
    for (auto [w, x, y]: edges) {
        total += w * uf.size_i(x) * uf.size_i(y);
        uf.unite(x, y);
    }

    cout << total << endl;
}
