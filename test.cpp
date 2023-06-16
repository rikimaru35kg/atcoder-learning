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

ll N;

ll ringl(ll x) {
    if (x < 0) return x % N + N;
    if (x >= 0) return x % N;
}
ll ringr(ll x) {
    if (x <= 0) return x % N + N;
    if (x <= N) return x;
    return x % N;
}

int main() {
    cin >> N;
    vl A(2*N);
    rep (i, N) {
        cin >> A.at(i); A.at(i+N) = A.at(i);
    }

    vvl dp(2*N, vl(2*N+1, -1e18));

    rep (i, 2*N) {
        dp.at(i).at(i) = 0;
        // if (N % 2 == 0) dp.at(i).at(i+1) = -1e18;
        // else dp.at(i).at(i+1) = A.at(i);
        dp.at(i).at(i+1) = A.at(i);
    }

    repk (width, 2, 2*N+1) {
        rep (l, 2*N-width) {
            if (l == 0 && width == 3) {
                cout << "";
            }
            ll r = l + width;
            if (width == 2) {
                dp.at(l).at(r) = max(A.at(l), A.at(r-1));
                continue;
            }
            if (A.at(l) < A.at(r-2)) dp.at(l).at(r) = max(dp.at(l).at(r), dp.at(l).at(r-2) + A.at(r-1));
            else dp.at(l).at(r) = max(dp.at(r).at(l), dp.at(l+1).at(r-1) + A.at(r-1));
            if (A.at(l+1) > A.at(r-1)) dp.at(l).at(r) = max(dp.at(l).at(r), dp.at(l+2).at(r) + A.at(l));
            else dp.at(l).at(r) = max(dp.at(l).at(r), dp.at(l+1).at(r-1) + A.at(l));
        }
    }

    ll max_p = 0;
    rep (i, N) max_p = max(max_p, dp.at(i).at(i+N));

    cout << max_p << endl;

}