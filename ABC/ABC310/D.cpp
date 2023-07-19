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
    ll N, T, M; cin >> N >> T >> M;
    vl A(M), B(M);
    vvl hate(N);
    rep (i, M) {
        ll a, b; cin >> a >> b; --a; --b;
        A[i] = a; B[i] = b;
        hate[a].push_back(b);
        hate[b].push_back(a);
    }

    ll ans = 0;
    auto dfs = [&] (auto dfs, ll idx, vvl st) -> void {
        if (idx == N) {
            if (SIZE(st) == T) ++ans;
            return;
        }
        rep (t, SIZE(st)) {
            vvl nst = st;
            bool flg_hate = false;
            if (idx == 5) {
                cout << "";
            }
            rep (pi, SIZE(st[t])) rep (pj, SIZE(hate[idx])) {
                if (st[t][pi] == hate[idx][pj]) flg_hate = true;
            }
            if (!flg_hate) {
                nst[t].push_back(idx);
                dfs(dfs, idx+1, nst);
            }
        }
        st.push_back(vl(1, idx));
        dfs(dfs, idx+1, st);
    };

    vvl emp;
    dfs(dfs, 0, emp);

    cout << ans << endl;
}
