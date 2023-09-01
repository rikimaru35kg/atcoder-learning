#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
typedef pair<double, double> Paird;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vpd vector<Paird>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvd vector<vector<vector<double>>>
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

// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;


vector<int> z_algo(string s) {
    int n = s.size();
    vector<int> a(n);
    int from = -1, last = -1;

    for (int i = 1; i < n; ++i) {
        int same = 0;
        if (from != -1) {
            same = min(a[i-from], last - i);
            same = max(same, 0);
        }
        while (i + same < n && s[same] == s[i+same]) ++same;
        a[i] = same;
        if(last < i + same) {
            from = i;
            last = i+same;
        }
    }
    a[0] = n;

    return a;
}

int main () {
    ll N; cin >> N;
    string T; cin >> T;

    string t1 = T.substr(0, N);
    string t2 = T.substr(N, N);
    reverse(all(t2));

    string s1 = t1 + t2;
    string s2 = t2 + t1;

    vi z1 = z_algo(s1);
    vi z2 = z_algo(s2);

    rep (i, N+1) {
        bool ok = true;
        if (i != 0 && z1[2*N-i] != i) {
            ok = false;
        }
        if (i != N && z2[2*N-(N-i)] != (N-i)) {
            ok = false;
        }
        if (ok) {
            cout << T.substr(0, i) + T.substr(2*N-(N-i), N-i) << endl;
            cout << i << endl;
            return 0;
        }
    }
    puts("-1");

}