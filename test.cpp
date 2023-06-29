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
const ll MOD2 = 998244353;

ll N;

vvvl dp;

vl convert(string s) {
    vl ret;
    rep (i, s.size()) {
        ret.push_back(s.at(i) - 'A');
    }
    return ret;
}

int main () {
    cin >> N;
    string S; cin >> S;
    dp.resize(N+1, vvl(1<<10, vl(10, 0)));
    vl Sint = convert(S);

    // dp.at(0).at(1<<Sint.at(0)).at(Sint.at(0)) = 1;
    rep (i, N) {
        // no selection
        rep (bit, 1<<10) {
            rep (n, 10) {
                dp.at(i+1).at(bit).at(n) += dp.at(i).at(bit).at(n);
                dp.at(i+1).at(bit).at(n) %= MOD2;
            }
        }
        // selection
        ll s = Sint.at(i);
        rep (bit, 1<<10) {
            rep (n, 10) {
                if ((bit & (1<<s)) != 0 && n == s) { // bitが立っていて（履歴あり）　かつ　最後がs
                    dp.at(i+1).at(bit).at(s) += dp.at(i).at(bit).at(s);
                    dp.at(i+1).at(bit).at(s) %= MOD2;
                }
                if ((bit & (1<<s)) == 0 && n != s) { // bitが立っていない（履歴無し）かつ最後がs以外
                    ll bit_new = bit^(1<<s);
                    dp.at(i+1).at(bit_new).at(s) += dp.at(i).at(bit).at(n);
                    dp.at(i+1).at(bit_new).at(s) %= MOD2;
                }
            }
        }
        dp.at(i+1).at(1<<s).at(s) += 1;
    }

    ll cnt = 0;
    rep (bit, 1<<10) {
        rep (n, 10) {
            cnt += dp.at(N).at(bit).at(n);
            cnt %= MOD2;
        }
    }
    

    cout << cnt << endl;
}