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
#define all(v) (v).begin(), (v).end()

bool gettable(ll point, vl &H, vl &S) {
    vl limit(H.size());
    rep (i, H.size()) {
        // if (point - H.at(i) < 0) return false;
        limit.at(i) = (point - H.at(i)) / S.at(i);
    }
    sort(limit.begin(), limit.end());
    rep (i, H.size()) {
        if (limit.at(i) < i) {
            return false;
        }
    }
    return true;
}

int main () {
    ll N; cin >> N;
    vl H(N), S(N);
    rep (i, N) cin >> H.at(i) >> S.at(i);

    ll left = 0, right = 1e18;
    while (abs(right - left) > 1) {
        ll mid = (left+right) / 2;
        if (gettable(mid, H, S)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << right << endl;
}
