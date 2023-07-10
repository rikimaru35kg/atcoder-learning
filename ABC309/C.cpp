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
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;

int main () {
    ll N, K; cin >> N >> K;
    vl a(N), b(N);
    ll max_day = 0;
    rep (i, N) {
        cin >> a[i] >> b[i];
        chmax(max_day, a[i]);
    }

    set<ll> comp(all(a));
    comp.insert(0);
    map<ll,ll> dct;
    ll idx = 0;
    for (auto x: comp) {
        dct[x] = idx;
        ++idx;
    }
    vl comp_vec(all(comp));

    vl imos(SIZE(comp)+1);
    rep (i, N) {
        ll x = dct[a[i]];
        imos[0] += b[i];
        imos[x] += -b[i];
    }

    rep (i, SIZE(imos)-1) {
        imos[i+1] += imos[i];
    }
    rep (i, SIZE(imos)) {
        if (imos[i] <= K) {
            cout << comp_vec[i]+1 << endl;
            return 0;
        }
    }

}
