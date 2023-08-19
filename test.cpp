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

struct Pos {
    ll x, y, k, c;
    Pos (ll _x, ll _y, ll _k, ll _c): x(_x), y(_y), k(_k), c(_c) {}
};

int main () {
    ll MOD = 998244353;
    ll N, M; cin >> N >> M;
    vl A(6);
    rep (i, 6) cin >> A[i];
    vl X(M), Y(M);
    rep (i, M) cin >> X[i] >> Y[i];
    set<Pair> obj;
    rep (i, M) obj.insert({X[i], Y[i]});

    map<Pair,ll> dp;
    dp[{0, 0}] = 1;
    rep (i, N) {
        map<Pair,ll> p;
        swap(p, dp);
        for (auto [k, v]: p) {
            ll x = k.first;
            ll y = k.second;
            rep(i, 3) {
                ll nx = x + A[2*i];
                ll ny = y + A[2*i+1];
                if(obj.count({nx, ny})) continue;
                (dp[{nx, ny}] += v) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (auto [_, v]: dp) {
        (ans += v) %= MOD;
    }
    cout << ans << endl;

    // map<ll,ll> mp_x;
    // rep (a, N+1) rep (b, N+1) rep(c, N+1) {
    //     if (a + b + c >= N+1) continue;
    //     ll x = a*A[0] + b*A[2] + c*A[4];
    //     mp_x[x] = 0;
    // }
    // ll idx = 0;
    // for (auto [k, v]: mp_x) {
    //     mp_x[k] = idx;
    //     ++idx;
    // }
    // vl xr;
    // for (auto [k, v]: mp_x) {
    //     xr.push_back(k);
    // }
    // map<ll,ll> mp_y;
    // rep (a, N+1) rep (b, N+1) rep (c, N+1) {
    //     if (a + b +c >= N+1) continue;
    //     ll x = a*A[1] + b*A[3] + c*A[5];
    //     mp_y[x] = 0;
    // }
    // idx = 0;
    // for (auto [k, v]: mp_y) {
    //     mp_y[k] = idx;
    //     ++idx;
    // }
    // vl yr;
    // for (auto [k, v]: mp_y) {
    //     yr.push_back(k);
    // }

    // ll nx = SIZE(mp_x), ny = SIZE(mp_y);
    // vvl cnt(nx, vl(ny));
    // cnt[mp_x[0]][mp_y[0]] = 1;

    // rep (i, N) {
    //     vvl p(nx, vl(ny));
    //     swap(p, cnt);
    //     rep(x, nx) rep (y, ny) {
    //         ll x_r = xr[x];
    //         ll y_r = yr[y];
    //         rep (k, 3) {
    //             ll x_n = x_r + A[2*k];
    //             ll y_n = y_r + A[2*k+1];
    //             if (obj.count({x_n, y_n})) continue;
    //             x_n = mp_x[x_n];
    //             y_n = mp_y[y_n];
    //             (cnt[x_n][y_n] += p[x][y]) %= MOD;
    //         }
    //     }
    // }

    // ll ans = 0;
    // rep (x, nx) rep(y, ny) {
    //     (ans += cnt[x][y]) %= MOD;
    // }
    // cout << ans << endl;

    // queue<Pos> que;
    // que.emplace(mp_x[0], mp_y[0], 0, 0);
    // set<Pair> ps;
    // while(!que.empty()) {
    //     auto [_x, _y, _k, _c] = que.front(); que.pop();
    //     ll x = _x; ll y = _y; ll k = _k; ll c = _c;
    //     if (cnt[x][y] != c) continue;
    //     ll x_r = xr[x], y_r = yr[y];
    //     rep (i, 3) {
    //         nx = x_r + A[2*i];
    //         ny = y_r + A[2*i + 1];
    //         if (obj.count({nx, ny})) continue;
    //         nx = mp_x[nx];
    //         ny = mp_y[ny];
    //         /*if (x != nx || y != ny)*/ (cnt[nx][ny] += cnt[x][y]) %= MOD;
    //         if (k < N - 1) que.emplace(nx, ny, k+1, cnt[nx][ny]);
    //         else ps.emplace(nx, ny);
    //     }
    // }

    // ll ans = 0;
    // for (auto [x, y]: ps) {
    //     (ans += cnt[x][y]) %= MOD;
    // }
    // cout << ans << endl;

}