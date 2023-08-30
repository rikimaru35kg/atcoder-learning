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
    vl stck(N);
    rep (i, N) {
        cin >> stck[i];
    }
    ll base = 0;
    set<ll> d_cnt;
    rep (i, N) d_cnt.insert(i);
    ll Q; cin >> Q;
    vvl query(Q);
    rep (i, Q) {
        ll t; cin >> t;
        if (t == 1) {
            ll x; cin >> x;
            base = x;
            d_cnt.clear();
        } else if (t == 2) {
            ll i, x; cin >> i >> x;
            --i;
            if (d_cnt.count(i)) stck[i] += x;
            else {
                d_cnt.insert(i);
                stck[i] = x;
            }
        } else {
            ll i; cin >> i;
            --i;
            if (d_cnt.count(i)) printf("%lld\n", stck[i] + base);
            else printf("%lld\n", base);
        }
    }
}