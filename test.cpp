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


struct BIT {
    ll n;
    vl bit;
    BIT (ll _n): n(_n+1), bit(_n+1) {}

    void add (ll i, ll x) {
        for (ll idx = i; idx < n; idx += (idx & (~idx+1))) {
            bit[idx] += x;
        }
    }
    ll sum (ll i) {
        ll ret = 0;
        for (ll idx = i; idx > 0; idx -= (idx & (~idx+1))) {
            ret += bit[idx];
        }
        return ret;
    }
};

ll flip_num(vl vec) {
    ll ret = 0;
    ll size = vec.size();
    map<ll,ll> cc;
    rep(i, size) cc[vec[i]] = 0;
    ll idx = 1;
    for (auto [k, v]: cc) {
        cc[k] = idx;
        idx++;
    }
    ll size2 = cc.size();
    BIT bit(size2);
    rep (i, size) {
        ret += (bit.sum(size2) - bit.sum(cc[vec[i]]));
        bit.add(cc[vec[i]], 1);
    }

    return ret;
}

int main () {
    ll N; cin >> N;
    vl C(N), X(N);
    rep (i, N) cin >> C[i];
    rep (i, N) cin >> X[i];

    map<ll,vl> mp;
    rep (i, N) {
        mp[C[i]].push_back(X[i]);
    }
    ll ans = 0;
    ans = flip_num(X);
    for (auto [k, v]: mp) {
        ans -= flip_num(v);
    }

    cout << ans << endl;

    
}