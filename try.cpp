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


struct fenwick_tree {
    ll n; vl bit;
    fenwick_tree (ll n): n(n+1), bit(n+1) {}

    void add(ll i, ll x) {
        for (ll idx=i; idx < n; idx += (-idx & idx)) bit[idx] += x;
    }
    ll sum(ll i) {
        ll ret = 0;
        for (ll idx=i; idx > 0; idx -= (-idx&idx)) ret += bit[idx];
        return ret;
    }
    ll lower_bound(ll x) {
        ll width = 1, l = 0;
        while ((width<<1) < n) width <<= 1;
        for (; width > 0; width >>= 1) {
            if (l + width >= n) continue;
            if (bit[l+width] >= x) continue;
            x -= bit[l+width];
            l += width;
        }
        return l+1;
    }
};
int main() {
    fenwick_tree bit(5);
    bit.sum(0);
}