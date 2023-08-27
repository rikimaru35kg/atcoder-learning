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
    ll H, W; cin >> H >> W;
    vs A(H);
    rep (i, H) cin >> A[i];

    vector<set<ll>> obj_row(H), obj_col(W);
    ll sx, sy, gx, gy;
    rep (i, H) rep (j, W) {
        char c = A[i][j];
        if (c == '>' || c == 'v' || c == '<' || c == '^' || c == '#') {
            obj_row[i].insert(j);
            obj_col[j].insert(i);
        }
        if (c == 'S') {sx = i; sy = j;};
        if (c == 'G') {gx = i; gy = j;};
    }

    vvl imos_r(H+1, vl(W+1));
    vvl imos_d(H+1, vl(W+1));
    rep (i, H) rep (j, W) {
        if (A[i][j] == '>') {
            imos_r[i][j] += 1;
            auto itr = obj_row[i].upper_bound(j);
            ll e = W-1;
            if (itr != obj_row[i].end()) {
                e = *itr;
            }
            imos_r[i][e+1] -= 1;
        }
        if (A[i][j] == '<') {
            imos_r[i][j+1] -= 1;
            auto itr = obj_row[i].lower_bound(j);
            ll e = 0;
            if (itr != obj_row[i].begin()) {
                --itr;
                e = *itr;
            }
            imos_r[i][e] += 1;
        }
        if (A[i][j] == 'v') {
            imos_d[i][j] += 1;
            auto itr = obj_col[j].upper_bound(i);
            ll e = H-1;
            if (itr != obj_col[j].end()) {
                e = *itr;
            }
            imos_d[e+1][j] -= 1;
        }
        if (A[i][j] == '^') {
            imos_d[i+1][j] -= 1;
            auto itr = obj_col[j].lower_bound(i);
            ll e = 0;
            if (itr != obj_col[j].begin()) {
                --itr;
                e = *itr;
            }
            imos_d[e][j] += 1;
        }
    }

    rep (j, W) {
        rep (i, H) {
            imos_r[i][j+1] += imos_r[i][j];
        }
    }
    rep (i, H) {
        rep (j, W) {
            imos_d[i+1][j] += imos_d[i][j];
        }
    }

    vl dx = {-1, 0, 1, 0};
    vl dy = {0, -1, 0, 1};

    vvl dist(H, vl(W, INF));
    dist[sx][sy] = 0;
    queue<Pair> que;
    que.emplace(sx, sy);
    while (!que.empty()) {
        auto [x, y] = que.front(); que.pop();
        rep (k, 4) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (obj_row[nx].count(ny) || obj_col[ny].count(nx)) continue;
            if (imos_r[nx][ny] > 0 || imos_d[nx][ny] > 0) continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                que.emplace(nx, ny);
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    if (dist[gx][gy] == INF) cout << -1 << endl;
    else cout << dist[gx][gy] << endl;

}
