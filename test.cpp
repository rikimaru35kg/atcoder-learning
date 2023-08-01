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
    vvl from(N);
    rep (i, M) {
        ll a, b; cin >> a >> b; --a; --b;
        from[a].push_back(b);
        from[b].push_back(a);
    }
    ll Q; cin >> Q;
    vl x(Q), k(Q);
    rep (i, Q) {
        ll _x, _k; cin >> _x >> _k; --_x;
        x[i] = _x; k[i] = _k;
    }

    auto bfs = [&](ll _x, ll _k) -> ll {
        ll ret = _x + 1;
        unordered_set<ll> visited;
        visited.insert(_x);
        queue<Pair> que;
        que.emplace(_x, 0);
        while(que.size()) {
            auto [v, d] = que.front(); que.pop();
            if (d >= _k) continue;

            for (auto nv: from[v]) {
                if (visited.count(nv)) continue;
                ret += nv + 1;
                visited.insert(nv);
                if (d+1 >= _k) continue;
                que.emplace(nv, d+1);
            }
        }
        return ret;
    };

    rep (i, Q) {
        ll _x = x[i], _k = k[i];
        ll ans = bfs(_x, _k);
        cout << ans << "\n";
    }
}