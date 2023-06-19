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

int main() {
    vl A = {10, 8, 7, 6, 6, 5};

    cout << upper_bound(all(A), 6, greater<ll>()) - A.begin() << endl;
    cout << lower_bound(all(A), 6, greater<ll>()) - A.begin() << endl;
    cout << lower_bound(all(A), 9, greater<ll>()) - A.begin() << endl;
    cout << lower_bound(all(A), 5, greater<ll>()) - A.begin() << endl;
    cout << upper_bound(all(A), 5, greater<ll>()) - A.begin() << endl;
}