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
const ll MOD = 998244353;

vp edges;
vl edge_cnt;
vvl from;
map<Pair,ll> dct_edge;

bool dfs(ll goal, ll x, ll org=-1){
    if (x == goal) return true;

    for (auto y: from[x]) {
        if (y == org) continue;
        if (dfs(goal, y, x)) {
            ll _x = min(x, y), _y = max(x, y);
            ll edge_num = dct_edge[Pair(_x, _y)]; 
            ++edge_cnt[edge_num];
            return true;
        }
    }
    return false;
}

int main () {
    ll N, M, K; cin >> N >> M >> K;
    vl A(M); rep (i, M) {ll a; cin >> a; A[i]=--a;}
    edge_cnt.resize(N-1);
    from.resize(N);
    rep (i, N-1) {
        ll u, v; cin >> u >> v; --u; --v;
        from[u].push_back(v);
        from[v].push_back(u);
        ll _u = min(u, v), _v = max(u, v);
        edges.push_back(Pair(_u, _v));
        dct_edge[Pair(_u, _v)] = i;
    }

    rep (i, M-1) {
        dfs(A[i+1], A[i]);
    }

    const ll DP_MAX = N*M;
    vl dp(2*DP_MAX+1, 0);
    dp[DP_MAX] = 1;
    vb visited(2*DP_MAX+1, false);
    visited[DP_MAX] = true;
    rep (i, N-1) {
        vl p(2*DP_MAX+1, 0);
        swap(p, dp);
        rep (j, 2*DP_MAX+1) {
            if (visited[j]) {
                ll pl = j + edge_cnt[i];
                ll mn = j - edge_cnt[i];
                if (pl < 2*DP_MAX+1) {
                    dp[pl] += p[j];
                    dp[pl] %= MOD;
                    visited[pl] = true;
                }
                if (mn >= 0) {
                    dp[mn] += p[j];
                    dp[mn] %= MOD;
                    visited[mn] = true;
                }
            }
        }
    }

    if (0 <= K+DP_MAX && K+DP_MAX < 2*DP_MAX+1) cout << dp[K+DP_MAX] << endl;
    else cout << "0" << endl;
}