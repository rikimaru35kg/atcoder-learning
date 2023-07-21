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

struct SCC {
    long long n;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num, rback_num;
    vector<vector<long long>> group;
    vector<bool> selected;
    SCC (long long _n): n(_n), from(_n), ifrom(_n) {}

    void add_edge (long long a, long long b) {
        from[a].push_back(b);
        ifrom[b].push_back(a);
    }

    void dfs1 (long long x, long long &bn) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (back_num[y] != -1) continue;
            if (selected[y]) continue;
            dfs1(y, bn);
        }
        back_num[x] = bn;
        rback_num[bn] = x;
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

    vector<vector<long long>> scc () {
        back_num.assign(n, -1);
        rback_num.assign(n, -1);
        selected.assign(n, false);
        long long bn = 0;
        for (long long i=0; i < n; ++i) {
            if (back_num[i] == -1) dfs1(i, bn);
        }
        sort(rback_num.begin(), rback_num.end());
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            ll x = rback_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            group.push_back(emp);
            dfs2(x, group.back());
        }
        return group;
    }
};


int main () {
    ll N, M; cin>>N>>M;
    vvl from(N);
    SCC sc(N);
    rep (i, M) {
        ll u, v; cin>>u>>v; --u;--v;
        from[u].push_back(v);
        sc.add_edge(u, v);
    }

    vvl gr = sc.scc();
    reverse(all(gr));
    ll gr_size = SIZE(gr);
    vector<ll> cyc(gr_size, -1);
    vector<ll> gi(N);
    rep (i, gr_size) {
        for (auto x: gr[i]) {
            gi[x] = i;
        }
    }
    rep (i, gr_size) {
        if (SIZE(gr[i])==1) {
            cyc[i] = 0;
            continue;
        }
        for (auto x: gr[i]) {
            for (auto y: from[x]) {
                if (cyc[gi[y]] == 0) continue;
            }
        }
    }


    cout << "";

}
