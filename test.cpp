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
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18;


int main () {
    ll N; cin >> N;
    vvl A(N, vl(N)), B(N, vl(N));
    rep (i, N) rep (j, N) cin >> A.at(i).at(j);

    B = A;

    rep (k, N) rep (i, N) rep (j, N) {
        B.at(i).at(j) = min(B.at(i).at(j), B.at(i).at(k) + B.at(k).at(j));
    }

    if (A != B) {
        cout << "-1" << endl;
        return 0;
    }

    ll road = 0;
    rep (i, N) rep (j, N) {
        if (i == j) continue;
        ll _min = INF;
        rep (k, N) {
            if (i == k || k == j) continue;
            _min = min(_min, B.at(i).at(k) + B.at(k).at(j));
        }
        if (_min > B.at(i).at(j)) road += B.at(i).at(j);
    }

    cout << road/2 << endl;
}
