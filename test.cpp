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


int main () {
    ll N, M; cin >>N >> M;
    vector<vector<tuple<ll,ll,ll>>> from(N);
    rep (i, M) {
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;
        from[a].emplace_back(b, i, c);
        from[b].emplace_back(a, i, c);
    }

    vl dist(N, INF);
    dist[0] = 0;
    vl edges;
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pque;
    pque.emplace(0, 0, -1); //{dist, vertex, edge_num}
    while(pque.size()) {
        auto [_d, _v, _n] = pque.top(); pque.pop();
        ll d = _d, v = _v, n = _n;
        if (dist[v] != d) continue;
        if (n != -1) edges.push_back(n);

        for (auto [nv, m, c]: from[v]) {
            if (dist[nv] > d + c) {
                dist[nv] = d + c;
                pque.emplace(dist[nv], nv, m);
            }
        }
    }

    rep (i, SIZE(edges)) cout << edges[i]+1 << " ";
    cout << endl;

}