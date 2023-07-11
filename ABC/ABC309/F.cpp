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
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 1e18;
const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117;

struct Box {
    vl vec;
    Box (ll h, ll w, ll d) {
        vec.push_back(h);
        vec.push_back(w);
        vec.push_back(d);
        sort(all(vec));
    }
};

int main () {
    ll N; cin >> N;
    vector<Box> boxes;
    rep (i, N) {
        ll h, w, d; cin >> h >> w >> d;
        boxes.push_back(Box(h, w, d));
    }

    vector<Box> save;
    save.push_back(boxes[0]);
    repk (i, 1, N) {
        rep (j, SIZE(save)) {
            if (boxes[i].vec[0] < save[j].vec[0] &&
                boxes[i].vec[1] < save[j].vec[1] &&
                boxes[i].vec[2] < save[j].vec[2] ||
                boxes[i].vec[0] > save[j].vec[0] &&
                boxes[i].vec[1] > save[j].vec[1] &&
                boxes[i].vec[2] > save[j].vec[2]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        save.push_back(boxes[i]);
    }

    cout << "No" << endl;

}
