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
#define vvvb vector<vector<vector<bool>>>
#define ql queue<ll>
#define dql deque<ll>
#define pql priority_queue<ll>
#define pqla priority_queue<ll,vl,greater<ll>>
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;


vl make_vec(Pair p1, Pair p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    ll gcd12 = gcd(abs(x2-x1), abs(y2-y1));
    vl vec12(2);
    if (x2-x1>=0) {
        vec12[0] = (x2-x1)/gcd12;
        vec12[1] = (y2-y1)/gcd12;
    } else {
        vec12[0] = -(x2-x1)/gcd12;
        vec12[1] = -(y2-y1)/gcd12;
    }
    return vec12;
}

bool is_line(Pair p1, Pair p2, Pair p3) {
    vl vec12 = make_vec(p1, p2);
    vl vec13 = make_vec(p1, p3);
    return(vec12 == vec13);
}

ll sign(ll x) {
    if (x > 0) return 1;
    if (x == 0) return 0;
    else return -1;
}

vl line_abc(Pair p1, Pair p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    ll a, b, c;
    if (y1 != y2) {
        a = (y2 - y1) * sign(y2 - y1);
        b = -(x2 - x1) * sign(y2 - y1);
        c = -x1*y2 + x2*y1 * sign(y2 - y1);
    } else {
        a = 0;
        b = -(x2 - x1) * sign(x2 - x1) * (-1);
        c = -x1*y2 + x2*y1 * sign(x2 - x1) * (-1);
    }
    ll g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g; b /= g; c /= g;
    vl v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    return v;
}

int main () {
    ll N, K; cin >> N >> K;
    vl X(N), Y(N);
    rep (i, N) cin >> X[i] >> Y[i];

    if (K <= 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    set<vl> st;
    rep (i, N) rep (j, i) {
        ll cnt = 0;
        Pair p1 = make_pair(X[i], Y[i]);
        Pair p2 = make_pair(X[j], Y[j]);
        rep (k, N) {
            if (k == i || k == j) continue;
            Pair p3 = make_pair(X[k], Y[k]);
            if (is_line(p1, p2, p3)) ++cnt;
        }
        if (cnt >= K - 2) {
            vl vec = line_abc(p1, p2);
            st.insert(vec);
        }
    }

    cout << SIZE(st) << endl;
}
