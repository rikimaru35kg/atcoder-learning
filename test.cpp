#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

int main() {
    ll N; cin >> N;
    vl a(N);
    rep (i, N) cin >> a.at(i);

    vvl dp(N, vl(N+1, 1e18));
    vvl sum(N, vl(N, 0));

    rep (i, N) {
        dp.at(i).at(i) = 0;
        dp.at(i).at(i+1) = 0;//a.at(i);
    }
    rep (i, N) {
        repk (j, i, N) {
            rep (k, j-i+1){
                sum.at(i).at(j) += a.at(i+k);
            }
        }
    }

    repk(w, 2, N+1) {
        rep (l, N-w+1) {
            ll r = l + w;
            repk (k, l, r) {
                dp.at(l).at(r) = min(dp.at(l).at(r), dp.at(l).at(k) + dp.at(k).at(r) + sum.at(l).at(r-1));
            }
        }
    }

    cout << dp.at(0).at(N) << endl;


}