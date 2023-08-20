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
    ll N; cin >> N;
    vvl from(N);
    vl indeg(N);
    rep (i, N) {
        ll c; cin >> c;
        rep (j, c) {
            ll p; cin >> p; --p;
            from[i].push_back(p);
            // ++indeg[p];
        }
    }

    vb visited(N);
    auto dfs = [&](auto f, ll v) -> void {
        for (auto nv: from[v]) {
            ++indeg[nv];
            if (visited[nv]) continue;
            f(f, nv);
        }
        visited[v] = true;
    };

    vb used(N);
    auto bfs = [&](ll x) -> vl {
        vl ret;
        queue<ll> que;
        que.push(x);
        // used[x] = true;
        while(que.size()) {
            ll v = que.front(); que.pop();
            ret.push_back(v);
            for (auto nv: from[v]) {
                --indeg[nv];
                // if (used[nv]) continue;
                if (indeg[nv] >= 1) continue;
                que.push(nv);
                // used[nv] = true;
            }
        }
        reverse(all(ret));
        return ret;
    };

    dfs(dfs, 0);

    vl ans = bfs(0);
    rep (i, SIZE(ans) - 1) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
