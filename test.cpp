#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define repr(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (int i = k; i < (int)(n); i++)

int main() {
    ll N, L; cin >> N >> L;
    vl dp(N+L+10, 0);
    const ll INF = 1000000007;

    dp.at(0) = 1;
    rep (i, N) {
        dp.at(i+L) += dp.at(i);
        if (dp.at(i+L) >= INF) dp.at(i+L) -= INF;
        dp.at(i+1) += dp.at(i);
        if (dp.at(i+1) >= INF) dp.at(i+1) -= INF;
    }

    cout << dp.at(N) << endl;


}
