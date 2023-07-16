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
    ll N, M; cin >> N >> M;
    vl P(N);
    vector<unordered_set<ll>> F(N);
    rep (i, N) {
        cin >> P[i];
        ll c; cin >> c;
        rep (j, c) {
            ll f; cin >> f;
            F[i].insert(f);
        }
    }

    bool ans = false;
    rep (i, N) rep (j, N) {
        if (P[i] < P[j]) continue;
        bool non_exist = false;
        for (auto f: F[i]) {
            if (!F[j].count(f)) {
                non_exist = true;
            }
        }
        if (non_exist) continue;
        if (P[i] > P[j] || SIZE(F[j]) > SIZE(F[i])) {
            ans = true;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
