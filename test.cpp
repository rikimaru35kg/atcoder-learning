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
    ll N, M; cin >> N >> M;
    vl A(N);
    rep (i, N) cin >> A.at(i);

    vb divs(100010, false);
    rep (i, N) {
        divs.at(A.at(i)) = true;
    }
    repk (i, 2, 100010) {
        for (ll k = 2; i*k < 100010; k++) {
            if (divs.at(i*k)) {
                divs.at(i) = true;
                break;
            }
        }
    }

    vb no_prime(M+1, false);
    repk (i, 2, 100010) {
        if (!divs.at(i)) continue;
        for (ll k = 1; i*k <= M; k++) {
            no_prime.at(i*k) = true;
        }
    }

    ll cnt = 0;
    repk (i, 1, M+1) {
        if (!no_prime.at(i)) cnt++;
    }

    cout << cnt << endl;
    repk (i, 1, M+1) {
        if (!no_prime.at(i)) cout << i << endl;
    }

}