#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug/debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
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
#define vp vector<Pair>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define ql queue<ll>
#define dql deque<ll>
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;


int main() {
    map<ll, ll> dct;

    cout << (dct.find(5) == dct.end()) << endl;
    cout << dct.count(5) << endl;
    cout << dct[5] << endl;
    cout << (dct.find(5) == dct.end()) << endl;
}