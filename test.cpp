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
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;
const ll MOD = 1e9 + 7;


int main () {
    ll N; cin >> N;
    vl S(2*N), T(2*N);
    rep (i, N) {
        cin >> S.at(i);
        S.at(i+N) = S.at(i);
    }
    rep (i, N) {
        cin >> T.at(i);
        T.at(i+N) = T.at(i);
    }

    vl times(2*N);
    rep (i, 2*N) {
        times.at(i) = T.at(i);
    }

    repk (i, 1, 2*N) {
        times.at(i) = min(times.at(i), times.at(i-1) + S.at(i-1));
    }

    rep (i, N) {
        cout << min(times.at(i), times.at(i+N)) << endl;
    }

}
