#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
typedef pair<double, double> Paird;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vpd vector<Paird>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvd vector<vector<vector<double>>>
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

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;

int main () {
    ll N, M; cin >> N >> M;
    vvl from(N);
    rep (i, M) {
        ll u, v; cin >> u >> v;
        --u; --v;
        from[u].push_back(v);
        from[v].push_back(u);
    }

    vvl graph;
    ll graph_num = 0;

    vl seen(N, -1);
    auto dfs = [&](auto f, ll x, ll z, ll org=-1) -> bool {
        seen[x] = z;
        ++graph[graph_num][z];
        for (auto y: from[x]) {
            if (y == org) continue;
            if (seen[y] == -1) {
                bool b = f(f, y, 1-z, x);
                if (!b) return false;
            } else {
                if (seen[y] == seen[x]) return false;
            }
        }
        return true;
    };

    rep (i, N) {
        if (seen[i] != -1) continue;
        graph.push_back(vl(2));
        bool b = dfs(dfs, i, 0);
        if (!b) {
            puts("0");
            return 0;
        }
        ++graph_num;
    }

    ll ans = N*(N-1)/2 - M;
    rep (i, graph_num) {
        ll n0 = graph[i][0];
        ans -= n0*(n0-1)/2;
        ll n1 = graph[i][1];
        ans -= n1*(n1-1)/2;
    }
    cout << ans << endl;

}