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

ll n_left (set<ll> &st, ll x) {
    if (SIZE(st) == 0) return -INF;
    auto itr = st.upper_bound(x);
    if (itr != st.begin()) return *(--itr);
    return -INF;
}
ll n_right (set<ll> &st, ll x) {
    if (SIZE(st) == 0) return INF;
    auto itr = st.upper_bound(x);
    if (itr != st.end()) return *itr;
    return INF;
}

int main () {
    ll H, W; cin >> H >> W;
    ll rs, cs; cin >> rs >> cs; --rs; --cs;
    ll N; cin >> N;
    map<ll,set<ll>> obj_r, obj_c;
    rep (i, N) {
        ll r, c; cin >> r >> c; --r; --c;
        obj_r[r].insert(c);
        obj_c[c].insert(r);
    }
    ll Q; cin >> Q;
    vc d(Q);
    vl l(Q);
    rep (i, Q) cin >> d[i] >> l[i];

    rep (i, Q) {
        char _d = d[i];
        ll _l = l[i];
        if (_d == 'U') {
            ll nx = n_left(obj_c[cs], rs);
            if (nx < 0) nx = 0;
            else ++nx;
            rs = max(nx, rs - _l);
        }
        if (_d == 'L') {
            ll nx = n_left(obj_r[rs], cs);
            if (nx < 0) nx = 0;
            else ++nx;
            cs = max(nx, cs - _l);
        }
        if (_d == 'D') {
            ll nx = n_right(obj_c[cs], rs);
            if (nx == INF) nx = H - 1;
            else --nx;
            rs = min(nx, rs + _l);
        }
        if (_d == 'R') {
            ll nx = n_right(obj_r[rs], cs);
            if (nx == INF) nx = W - 1;
            else --nx;
            cs = min(nx, cs + _l);
        }

        printf("%lld %lld\n", rs+1, cs+1);
    }

}