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
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()push
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;



int main () {
    ll N; cin >> N;
    vs S(N);
    rep (i, N) cin >> S[i];
    ll js = 6;

    auto judge4 = [&](string str) -> bool {
        ll cnt = 0;
        rep (i, js) {
            if (str[i] == '#') ++cnt;
        }
        if (cnt >= 4) return true;
        else return false;
    };

    bool ok = false;
    rep (i, N-js+1) rep (j, N-js+1) {
        string str_tmp = "";
        rep (k, js) str_tmp += S[i+k][j+k];
        if (judge4(str_tmp)) ok = true;

        str_tmp = "";
        rep (k, js) str_tmp += S[i+k][j+js-1-k];
        if (judge4(str_tmp)) ok = true;
    }

    rep (i, N) rep (j, N-js+1) {
        string str_tmp = S[i].substr(j, js);
        if (judge4(str_tmp)) ok = true;
    }
    rep (i, N-js+1) rep (j, N) {
        string str_tmp = "";
        rep (k, js) str_tmp += S[i+k][j];
        if (judge4(str_tmp)) ok = true;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
