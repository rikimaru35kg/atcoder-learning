#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
typedef pair<double, double> Paird;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vpd vector<Paird>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvd vector<vector<vector<double>>>
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
    vs S(N);
    rep (i, N) cin >> S[i];
    ll n2 = 1<<N;

    vvl from(N);
    rep (i, N) rep (j, N) {
        if (i == j) continue;
        if (S[i].back() == S[j][0]) {
            from[i].push_back(j);
        }
   }

    vvl mem(n2, vl(N, -1));
    auto dfs = [&](auto f, ll s, ll v) -> bool {
        if (mem[s][v] != -1) return mem[s][v];
        bool ret = false;
        bool nxt = false;
        for (auto nv: from[v]) {
            if (s>>nv&1) continue;
            nxt = true;
            ll ns = s | 1<<nv;
            ret |= !f(f, ns, nv);
        }
        if (!nxt) return (mem[s][v] = 1);
        if (ret) return (mem[s][v] = 1);
        return (mem[s][v] = 0);
    };

    bool ans = false;
    rep (i, N) {
        ans |= dfs(dfs, 1<<i, i);
    }
    if (ans) puts("First");
    else puts("Second");
}
