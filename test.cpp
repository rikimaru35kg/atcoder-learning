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

long long get_rand_range( long long min_val, long long max_val ) {
    // 乱数生成器（メルセンヌツイスタ）
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<long long> get_rand_uni_int( min_val, max_val );

    // 乱数を生成
    return get_rand_uni_int(mt64);
}


int main () {
    ll N; cin >> N;
    vl a(N), b(N);
    rep (i, N) cin >> a[i];
    rep (i, N) cin >> b[i];
    ll Q; cin >> Q;
    vl x(Q), y(Q);
    rep (i, Q) cin >> x[i] >> y[i];

    unordered_set<ll> stA;
    unordered_set<ll> stB;
    map<ll,ll> hash;
    rep (i, N) {
        hash[a[i]] = get_rand_range(0, INF);
        hash[b[i]] = get_rand_range(0, INF);
    }

    stA.insert(a[0]);
    stB.insert(b[0]);
    vl hsh_A, hsh_B;
    hsh_A.push_back(hash[a[0]]);
    hsh_B.push_back(hash[b[0]]);
    rep (i, N) {
        if (i == 0) continue;
        if (stA.insert(a[i]).second) hsh_A.push_back(hsh_A.back() ^ hash[a[i]]);
        else hsh_A.push_back(hsh_A.back());
        if (stB.insert(b[i]).second) hsh_B.push_back(hsh_B.back() ^ hash[b[i]]);
        else hsh_B.push_back(hsh_B.back());
    }
    

    rep (i, Q) {
        if (hsh_A[x[i]-1] == hsh_B[y[i]-1]) puts("Yes");
        else puts("No");
    }

}