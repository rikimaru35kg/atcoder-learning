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
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()push
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;


int main () {
    ll N, M; cin>>N>>M;
    vvl from(N);
    rep (i, M) {
        ll u, v; cin>>u>>v; --u;--v;
        from[u].push_back(v);
    }

    vl state(N, -1);
    vb used(N);

    auto dfs = [&](auto f, ll x) -> void {
        if (used[x]) {
            state[x] = 1;
            return;
        }
        used[x] = true;
        for (auto y: from[x]) {
            if (state[y] == 0) continue;
            if (state[y] == 1) {
                state[x] = 1;
                break;
            }
            f(f, y);
            if (state[y] == 1) state[x] = 1;
        }
        if (state[x] != 1) state[x] = 0;
        used[x] = false;
    };

    rep (i, N) {
        if (state[i] != -1) continue;
        dfs(dfs, i);
    }

    ll ans = 0;
    rep (i, N) {
        if (state[i] == 1) ++ans;
    }

    cout << ans << endl;


}
