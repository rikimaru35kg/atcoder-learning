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



int main () {
    string S; cin >> S;

    ll length = 0;
    rep (i, S.size()) {
        repk (j, i, S.size()) {
            if (j == 6) {
                cout << "";
            }
            string S_sub = S.substr(i, j-i+1);
            // repk (k, i, j+1) S_sub += S.at(k);
            bool acgt = false;
            // for (char x: S_sub) {
            //     if (x != 'A' && x != 'C' && x != 'G' && x != 'T') acgt = false;
            // }
            if (regex_match(S_sub, regex("[ACGT]+"))) acgt = true;
            if (acgt) {
                length = max(length, j-i+1);
            }
        }
    }

    cout << length << endl;

}