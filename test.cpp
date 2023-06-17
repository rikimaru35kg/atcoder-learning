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
vl c;
vl lis;
ll INF = 1e18;

int main() {
    cin >> N;
    c.resize(N);
    lis.resize(N, INF);
    rep (i, N) cin >> c.at(i);

    rep (i, N) {
        ll idx = lower_bound(all(lis), c.at(i)) - lis.begin();
        lis.at(idx) = c.at(i);
    }

    ll cnt = 0;
    rep (i, N) {
        if (lis.at(i) == INF) {
            cnt = i;
            break;
        }
    }

    if (cnt == 0) cout << "0" << endl;
    else cout << (N-cnt) << endl;
}