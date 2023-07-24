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
    ll x, y, dir;
    Pos (ll _x, ll _y, ll _dir): x(_x), y(_y), dir(_dir) {}
};

int main () {
    ll N, M; cin >> N >> M;
    vs S(N); 
    rep (i, N) cin >> S[i];

    vl dx = {1, 0, -1, 0};
    vl dy = {0, 1, 0, -1};
    vvb ok(N, vb(M));
    vvvb used(N, vvb(M, vb(4)));

    queue<Pos> que;
    que.emplace(1, 1, 0);
    que.emplace(1, 1, 1);
    ok[1][1] = true;
    while(que.size()) {
        auto [_x, _y, _dir] = que.front(); que.pop();
        ll x = _x, y = _y, dir = _dir;
        if (used[x][y][dir]) continue;
        used[x][y][dir] = true;
        ll nx = x + dx[dir];
        ll ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (S[nx][ny] == '#') {
            rep (k, 4) {
                if ((k % 2) == (dir % 2)) continue;
                if (used[x][y][k]) continue;
                que.emplace(x, y, k);              
            }
        }
        else if (!used[nx][ny][dir]) {
            ok[nx][ny] = true;
            que.emplace(nx, ny, dir);
        }
    }

    ll ans = 0;
    repk (i, 1, N-1) repk (j, 1, M-1) {
        if (ok[i][j]) ++ans;
    }
    cout << ans << endl;
}
