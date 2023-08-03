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
    vl h(3), w(3);
    rep (i, 3) cin >> h[i];
    rep (i, 3) cin >> w[i];

    ll M = 28;
    ll ans = 0;
    rep1 (i, M) rep1 (j, M) rep1 (k, M) rep1 (l, M) {
        vvl A(3, vl(3));
        A[0][0] = i; A[0][1] = j; A[1][0] = k; A[1][1] = l;
        A[0][2] = h[0] - A[0][0] - A[0][1]; if (A[0][2] < 1) continue;
        A[1][2] = h[1] - A[1][0] - A[1][1]; if (A[1][2] < 1) continue;
        A[2][0] = w[0] - A[0][0] - A[1][0]; if (A[2][0] < 1) continue;
        A[2][1] = w[1] - A[0][1] - A[1][1]; if (A[2][1] < 1) continue;
        A[2][2] = h[2] - A[2][0] - A[2][1]; if (A[2][2] < 1) continue;
        // ll h_q = 0; rep (m, 3) h_q += A[2][m];
        ll w_q = 0; rep (m, 3) w_q += A[m][2];
        if (w_q == w[2]) ++ans;
    }

    cout << ans << endl;
}