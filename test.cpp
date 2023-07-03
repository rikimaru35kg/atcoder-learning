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
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;


int main () {
    ll N; cin >> N;
    vl x(N), y(N);
    rep (i, N) cin >> x.at(i) >> y.at(i);
    set<Pair> dct;

    vl ver, hor;
    map<ll,ll> dct_v, dct_h;
    rep (i, N) {
        if(dct_v[x.at(i)] == 1) ver.push_back(x.at(i));
        if(dct_h[y.at(i)] == 1) hor.push_back(y.at(i));
        dct_v[x.at(i)]++;
        dct_h[y.at(i)]++;
        dct.insert(Pair(x.at(i), y.at(i)));
    }

    ll cnt = 0;
    rep (v1, ver.size()) {
        repk (v2, v1+1, ver.size()) {
            rep (h1, hor.size()) {
                repk (h2, h1+1, hor.size()) {
                    if (v1==2 && v2==3 && h1==1 && h2==2) {
                        cout << "";
                    }
                    if (dct.count(Pair(ver.at(v1), hor.at(h1))) &&
                        dct.count(Pair(ver.at(v1), hor.at(h2))) &&
                        dct.count(Pair(ver.at(v2), hor.at(h1))) &&
                        dct.count(Pair(ver.at(v2), hor.at(h2)))) {
                        ++cnt;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
}