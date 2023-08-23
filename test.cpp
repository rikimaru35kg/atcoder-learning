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
    ll N, M; cin >> N >> M;
    vl A(N);
    rep (i, N) {
        ll a; cin >> a;
        A[i] = a;
    }
    vvl from(N);
    vp edges(M);
    rep (i, M) {
        ll u, v; cin >> u >> v; --u; --v;
        from[u].push_back(v);
        from[v].push_back(u);
        edges[i] = {u, v};
    }

    vl cost(N);
    rep (i, M) {
        auto [u, v] = edges[i];
        cost[u] += A[v];
        cost[v] += A[u];
    }

    auto delcost = [&](ll x, vl &co) -> void {
        for (auto y: from[x]) {
            co[y] -= A[x];
        }
    };

    auto ok = [&](ll x) -> bool {
        vl _cost = cost;
        vb deleted(N);
        queue<ll> que;
        ll num = 0;
        rep (v, N) {
            if (_cost[v] <= x) {
                que.push(v);
                deleted[v] = true;
                ++num;
            }
        }
        while(!que.empty()) {
            ll v = que.front(); que.pop();
            delcost(v, _cost);
            // deleted[v] = true;
            for (auto nv: from[v]) {
                if (deleted[nv]) continue;
                if (_cost[nv] > x) continue;
                que.push(nv);
                deleted[nv] = true;
                ++num;
            }
        }
        if (num == N) return true;
        else return false;
    };

    ll left = -1, right = INF;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        bool tmp = ok(mid);
        if (tmp) right = mid;
        else left = mid;
    }

    cout << right << endl;

}
