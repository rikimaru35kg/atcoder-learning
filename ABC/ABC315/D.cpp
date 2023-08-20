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
    ll H, W; cin >> H >> W;
    vs c(H);
    rep (i, H) cin >> c[i];

    cout << "";

    vector<map<char,ll>> hs(H);
    vector<map<char,ll>> ws(W);
    rep (h, H) rep (w, W) {
        // cout << h + w << endl;
        char chr = c[h][w];
        hs[h][chr]++;
        ws[w][chr]++;
    }

    unordered_set<ll> hidx;
    rep (i, H) hidx.insert(i);
    unordered_set<ll> widx;
    rep (i, W) widx.insert(i);
    while (true) {
        unordered_set<ll> he, we;
        if (SIZE(widx) >= 2) {
            for (auto h: hidx) {
                if (SIZE(hs[h]) == 1) he.insert(h);
            }
        }
        if (SIZE(hidx) >= 2) {
            for (auto w: widx) {
                if (SIZE(ws[w]) == 1) we.insert(w);
            }
        }
        if (SIZE(he) == 0 && SIZE(we) == 0) break;
        for (auto h: he) {
            for (auto w: widx) {
                char chr = c[h][w];
                hs[h][chr]--;
                if (hs[h][chr] == 0) hs[h].erase(chr);
                ws[w][chr]--;
                if (ws[w][chr] == 0) ws[w].erase(chr);
            }
        }
        for (auto w: we) {
            for (auto h: hidx) {
                if (he.count(h)) continue;
                char chr = c[h][w];
                hs[h][chr]--;
                if (hs[h][chr] == 0) hs[h].erase(chr);
                ws[w][chr]--;
                if (ws[w][chr] == 0) ws[w].erase(chr);
            }
        }
        // for (auto h: hidx) for (auto w: widx) {
        //     char chr = c[h][w];
        //     // printf("%lld, %lld, %c\n", h, w, chr);
        //     if (he.count(h) || we.count(w)) {
        //         hs[h][chr]--;
        //         if (hs[h][chr] == 0) hs[h].erase(chr);
        //         ws[w][chr]--;
        //         if (ws[w][chr] == 0) ws[w].erase(chr);
        //     }
        // }
        for (auto h: he) hidx.erase(h); 
        for (auto w: we) widx.erase(w); 
    }

    cout << SIZE(hidx) * SIZE(widx) << endl;
    
}
