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
    vvl FS(N);
    rep (i, N) {
        ll f, s; cin >> f >> s; --f;
        FS[f].push_back(s);
    }

    rep (i, N) {
        sort(allr(FS[i]));
    }
    ll ans = 0;
    rep (i, N) {
        if (SIZE(FS[i]) >= 2) {
            ll x = FS[i][0];
            ll y = FS[i][1];
            ll s = max(x, y) + min(x, y)/2;
            chmax(ans, s);
        }
    }
    vl diffs;
    rep (i, N) {
        if (SIZE(FS[i]) >= 1) {
            diffs.push_back(FS[i][0]);
        }
    }
    sort(allr(diffs));
    if (SIZE(diffs) >= 2) {
        ll x = diffs[0];
        ll y = diffs[1];
        chmax(ans, x + y);
    }
    cout << ans << endl;
}
