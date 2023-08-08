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
    ll N, Q, X; cin >> N >> Q >> X;
    vl W(2*N);
    rep (i, N) {
        cin >> W[i];
        W[i+N] = W[i];
    }

    ll Wtotal = 0;
    rep (i, N) Wtotal += W[i];
    ll rem = X % Wtotal;
    ll q = X / Wtotal;

    ll r = 0;
    vl nxt(N), ans(N);
    ll sum = 0;
    rep (l, N) {
        while (r < 2*N && sum < rem) {
            sum += W[r];
            ++r;
        }
        nxt[l] = r;
        ans[l] = q * N + r - l;
        
        if (l == r) ++r;
        else sum -= W[l];
    }
    rep (i, N) nxt[i] %= N;

    ll spos = 0;
    vl cnt; ll idx = 0;
    cnt.push_back(0);
    vb seen(N);
    rep (i, N) {
        seen[idx] = true;
        ll ni = nxt[idx];
        if (seen[ni]) {
            rep (j, SIZE(cnt)) {
                if (cnt[j] == ni) break;
                ++spos;
            }
            break;
        }
        cnt.push_back(ni);
        idx = ni;
    }
    ll csize = SIZE(cnt) - spos;

    rep (i, Q) {
        ll k; cin >> k; --k;
        ll num;
        if (k <= spos) {
            num = k;
        }
        else {
            num = spos + (k - spos) % csize;
        }
        cout << ans[cnt[num]] << endl;
    }


}
