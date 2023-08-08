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


int main () {
    ll N, K; cin >> N >> K;
    vl A(N);

    auto ques = [&](vl vec) -> ll {
        cout << "?" << " ";
        rep (i, K) cout << vec[i] << " ";
        cout << endl;
        ll res; cin >> res;
        return res;
    };

    vl res;
    ll total = 0;
    rep1(i, K+1) {
        vl x;
        rep1 (j, K+1) {
            if (i==j) continue;
            x.push_back(j);
        }
        ll r = ques(x);
        res.push_back(r);
        total ^= r;
    }
    rep (i, K+1) {
        A[i] = total ^ res[i];
    }

    ll Km1 = 0;
    vl q;
    rep1 (i, K-1) {
        q.push_back(i);
        Km1 ^= A[i-1];
    }
    repk (i, K+2, N+1) {
        q.push_back(i);
        ll r = ques(q);
        A[i-1] = r ^ Km1;
        q.pop_back();
    }

    cout << "! ";
    rep (i, N) cout << A[i] << ' ';
    cout << endl;

}