// ### test.cpp ###
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = pair<ll, ll>;
using Paird = pair<double, double>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<double>;
using vp = vector<Pair>;
using vpd = vector<Paird>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvd = vector<vector<double>>;
using vvs = vector<vector<string>>;
using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<ll>>>;
using vvvb = vector<vector<vector<bool>>>;
using vvvd = vector<vector<vector<double>>>;
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
#define PYes {puts("Yes"); return 0;}
#define PNo {puts("No"); return 0;}
#define Pdame {puts("-1"); return 0;}
#define Out(x) cout << (x) << endl;
#define print_vec(vec) {for (auto x: vec) cout << x << ' '; cout << endl;}
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;

struct SCC {
    SCC (long long _n): n(_n), from(_n), ifrom(_n) {}

    void add_edge (long long a, long long b) {
        from[a].push_back(b);
        ifrom[b].push_back(a);
    }

    vector<vector<long long>> scc () {
        vector<vector<long long>> group;
        back_num.clear();
        selected.assign(n, false);
        for (long long i=0; i < n; ++i) {
            if (!selected[i]) dfs1(i);
        }
        selected.assign(n, false);
        for (long long i=n-1; i >= 0; --i) {
            long long x = back_num[i];
            if (selected[x]) continue;
            vector<long long> emp;
            dfs2(x, emp);
            group.push_back(emp);
        }
        return group;
    }

private:
    long long n;
    vector<vector<long long>> from, ifrom;
    vector<long long> back_num;
    vector<bool> selected;

    void dfs1 (long long x) {
        selected[x] = true;
        for (auto y: from[x]) {
            if (selected[y]) continue;
            dfs1(y);
        }
        back_num.push_back(x);
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
    vl A(N);
    vl indeg(N);
    rep (i, N) cin >> A[i];
    rep (i, N) --A[i];

    SCC scc(N);
    rep (i, N) scc.add_edge(i, A[i]);
    vvl groups = scc.scc();
    ll ans = 0;
    rep (i, SIZE(groups)) {
        vl gr = groups[i];
        if (SIZE(gr) >= 2) ans += SIZE(gr);
        if (SIZE(gr) == 1 && gr[0] == A[gr[0]]) ++ans;
    }
    Out(ans)

}

// ### test.cpp ###
