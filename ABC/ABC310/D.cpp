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
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;


int main () {
    ll N, T, M; cin >> N >> T >> M;
    vl A(M), B(M);
    rep (i, M) {
        ll a, b; cin >> a >> b; --a; --b;
        A[i] = a; B[i] = b;
    }

    vector<vector<unordered_set<ll>>> stock;
    auto dfs = [&] (auto dfs, ll idx, vector<unordered_set<ll>> st, ll sp) -> void {
        if (idx == N-1) {
            stock.push_back(st);
            return;
        }
        rep (t, T) {
            if (t > sp) break;
            vector<unordered_set<ll>> nst = st;
            nst[t].insert(idx);
            ll nsp = sp;            
            if (t == sp) ++nsp;
            dfs(dfs, idx+1, nst, nsp);
        }
    };

    vector<unordered_set<ll>> ist(T);
    dfs(dfs, 0, ist, 0);

    ll ans = 0;
    rep (i, SIZE(stock)) {
        vl team(T);
        rep (t, T) {
            for (auto x: stock[i][t]) {
                team[x] = t;
            }
        }
        bool ok = true;
        rep (m, M) {
            if (team[A[m]] == team[B[m]]) {
                ok = false; break;
            }
        }
        if (ok) ++ans;
    }

    cout << "";
}
