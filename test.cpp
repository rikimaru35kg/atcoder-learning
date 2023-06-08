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
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    ll cost;
    if (2 * C <= A && 2 * C <= B) {
        cost = 2 * max(X, Y) * C;
    }
    else if (2 * C <= A) {
        if (X >= Y) {
            cost = 2 * X * C;
        }
        else{
            cost = 2 * X * C + (Y - X) * B;
        }
    }
    else if (2 * C <= B) {
        if (X <= Y) {
            cost = 2 * Y * C;
        }
        else{
            cost = 2 * Y * C + (X - Y) * A;
        }
    }
    else if (2 * C <= (A + B)) {
        if (X >= Y) {
            cost = 2 * Y * C + (X - Y) * A;
        }
        else {
            cost = 2 * X * C + (Y - X) * B;
        }
    }
    else {
        cost = X * A + Y * B;
    }

    cout << cost << endl;
}