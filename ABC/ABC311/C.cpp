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
    vl from(N);
    rep (i, N) {
        ll a; cin >> a; --a;
        from[i] = a;
    }

    vb finished(N);
    vb seen(N);
    vl stck;
    ll pos = -1;

    auto dfs = [&](auto f, ll x) -> void {
        seen[x] = true;
        stck.push_back(x);
        ll y = from[x];
        if (!finished[y]) {
            if (seen[y] && !finished[y]) {
                pos = y;
                return;
            }

            f(f, y);

            if (pos != -1) return;
        }

        stck.pop_back();
        finished[x] = true;
    };

    rep (i, N) {
        seen.assign(N, false);
        pos = -1;
        if (finished[i]) continue;
        dfs(dfs, i);
        if (SIZE(stck) > 0) {
            ll idx = 0;
            while (pos != stck[idx]) {
                idx++;
            }
            cout << (SIZE(stck)-idx) << endl;
            repk (k, idx, SIZE(stck)) {
                if (k != SIZE(stck)-1) cout << stck[k]+1 << " ";
                else cout << stck[k]+1 << endl;
            }
            return 0;
        }
    }
}
