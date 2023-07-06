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

int main () {
    ll N = 9;
    ll M; cin >> M;
    vvl from(N);
    rep (i, M) {
        ll u, v; cin >> u >> v;
        --u; --v;
        from[u].push_back(v);
        from[v].push_back(u);
    }
    vl piece(N, -1);
    rep(i, 8) {
        int x; cin >> x; --x;
        piece[x] = i;
    }

    vl target = {0, 1, 2, 3, 4, 5, 6, 7, -1};
    map<vl, int> dist;
    dist[piece] = 0;
    queue<vl> que;
    que.push(piece);
    while(que.size()) {
        vl state = que.front();
        que.pop();

        int x;
        rep (i, N) {
            if (state[i] == -1) {
                x = i;
            }
        }
        for (auto y: from[x]) {
            vl nstate = state;
            swap(nstate[y], nstate[x]);
            if (dist.count(nstate)) continue;
            que.push(nstate);
            dist[nstate] = dist[state] + 1;
        }
    }

    if (!dist.count(target)) cout << -1 << endl;
    else cout << dist[target] << endl;

}