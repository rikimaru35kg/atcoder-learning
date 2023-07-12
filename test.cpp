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
#define pql priority_queue<ll>
#define pqla priority_queue<ll,vl,greater<ll>>
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;

template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        if (l < 0 || l > n || r < 0 || r > n) {
            cout << "index used for BIT.add() is out of range" << endl;
            return;
        }
        ++l; ++r;  // 0-indexed --> 1-indexed
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    void add1(int i, T x) {  // 要素iにxを加算
        if (i < 0 || i > n) {
            cout << "index used for BIT.add1() is out of range" << endl;
            return;
        }
        add(i, i+1, x);
    }
    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) {
        if (i < 0 || i > n) {
            cout << "index used for BIT.sum() is out of range" << endl;
        }
        ++i;  // 0-indexed --> 1-indexed
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }
};


int main () {
    ll N; cin >> N;
    vl A(N), B(N);
    rep (i, N) cin >> A[i];
    rep (i, N) cin >> B[i];
    rep (i, N) B[i] *= -1;
    map<ll, vl> AB;
    rep (i, N) {
        AB[A[i]].push_back(B[i]);
    }
    map<ll,ll> cc;
    rep (i, N) {
        cc[B[i]] = 0;
    }
    ll i = 0;
    for (auto [k, v] : cc) {
        cc[k] = i++;
    }

    BIT<ll> bit(N);
    ll cnt = 0;
    for (auto [a, b_vec]: AB) {
        for (auto b: b_vec) {
            bit.add1(cc[b], 1);
        }
        for (auto b: b_vec) {
            cnt += bit.sum(cc[b]);
        }
    }

    cout << cnt << endl;

}

