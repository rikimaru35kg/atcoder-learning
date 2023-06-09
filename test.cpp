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
    ll N, K; cin >> N >> K;
    vl a(N);
    rep (i, N) cin >> a.at(i);

    ll min_cost = 1LL<<62;
    for (ll i = 1; i < (1<<N); i+=2) {
        bitset<15> p(i);
        if (p.count() != K) continue;
        ll cost = 0;
        ll height = a.at(0);
        repk (j, 1, N) {
            if (p.test(j) == false) {
                height = max(height, a.at(j));
            }
            else {
                cost += max(height - a.at(j) + 1, 0LL);
                height = max(a.at(j), height + 1);
            }
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
}


