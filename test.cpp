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
struct SCC {
    SCC (long long _n): n(_n), from(_n), ifrom(_n) {}

    void add_edge (long long a, long long b) {
        from[a].push_back(b);
        ifrom[b].push_back(a);
    }

    vector<vector<long long>> scc () {
        vector<vector<long long>> group;
        back_num.assign(n, -1);
        selected.assign(n, false);
        bn = 0;
        for (long long i=0; i < n; ++i) {
            if (!selected[i]) dfs1(i);
        }
        reverse(back_num.begin(), back_num.end());
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            long long x = back_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            dfs2(x, emp);
            group.push_back(emp);
        }
        return group;
    }

private:
    long long n, bn;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num;
    vector<bool> selected;

    void dfs1 (long long x) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (selected[y]) continue;
            dfs1(y);
        }
        back_num[bn] = x;
        ++bn;
    }

    void dfs2 (long long x, vector<long long> &vec) {
        selected[x] = true;
        vec.push_back(x);
        for (auto y: ifrom[x]) {
            if (selected[y]) continue;
            dfs2(y, vec);
        }
    }
};


int main () {
    ll N; cin >> N;
    SCC scc(N);
    rep (i, N) {
        ll x; cin >> x; --x;
        scc.add_edge(i, x);
    }
    vl C(N);
    rep (i, N) cin >> C[i];

    vvl group = scc.scc();

    ll ans = 0;
    rep (i, SIZE(group)) {
        vl gr = group[i];
        if (SIZE(gr) == 1) continue;
        ll tmp = INF;
        for (auto x: gr) {
            chmin(tmp, C[x]);
        }
        ans += tmp;
    }

    cout << ans << endl;

}