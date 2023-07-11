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
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;

vvl from;

ll bfs(ll start, ll n) {
    ll dist_max = 0;
    vl dist(n, -1);

    queue<ll> que;
    que.push(start);
    dist[start] = 0;
    while(que.size()) {
        ll v = que.front(); que.pop();

        for (auto x: from[v]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[v] + 1;
            chmax(dist_max, dist[x]);
            que.push(x);
        }
    }

    return dist_max;
}

int main () {
    ll N1, N2, M; cin >> N1 >> N2 >> M;
    from.resize(N1+N2);
    rep (i, M) {
        ll a, b; cin >> a >> b; --a; --b;
        from[a].push_back(b);
        from[b].push_back(a);
    }

    ll dist1 = bfs(0, N1);
    ll dist2 = bfs(N1+N2-1, N1+N2);

    cout << dist1 + dist2 + 1 << endl;

}
