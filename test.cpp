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
    vl X(N);
    rep (i, N) cin >> X[i];
    vl C(M), Y(M);
    rep (i, M) cin >> C[i] >> Y[i];
    map<ll,ll> bonus;
    rep (i, M) bonus[C[i]] = Y[i];

    vl dp(N+1);
    dp[1] = X[0];
    dp[1] += bonus[1];
    repk (i, 1, N) {
        vl p(N+1);
        swap (p, dp);
        rep (cnt, N) {
            if (p[cnt] > 0) {
                dp[cnt+1] += p[cnt] + X[i];
                dp[cnt+1] += bonus[cnt+1];
            }
        }
        rep1 (cnt, N)
        chmax(dp[0], p[cnt]);
    }

    ll ans = -1;
    rep (i, N+1) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
}