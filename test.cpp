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
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()

const ll INF = 1e18;
ll N, M;
vvl dp;
vvl dist, times;
vvl path;

ll rec(ll bits, ll v) {
    bitset<20> tmp(bits);
    if (tmp.count() == 1) {
        return dp.at(bits).at(v);
    }

    if (dp.at(bits).at(v) != -1) return dp.at(bits).at(v);

    ll _min = INF;
    ll cnt = 0;
    rep (u, N) {
        if ((bits & (1<<u)) == 0) continue;
        if (u == v) continue;
        if (dist.at(u).at(v) == INF) continue;
        ll n_bits = (bits^(1<<v));
        ll n_path = rec(n_bits, u);
        if (n_path + dist.at(u).at(v) > times.at(u).at(v)) continue;
        if (_min > n_path + dist.at(u).at(v)) {
            cnt = path.at(n_bits).at(u);
        }
        else if (_min == n_path + dist.at(u).at(v)) {
            cnt += path.at(n_bits).at(u);
        }
        _min = min(_min, n_path + dist.at(u).at(v));
    }
    dp.at(bits).at(v) = _min;
    path.at(bits).at(v) = cnt;
    return _min;
}

int main() {
    cin >> N >> M;
    dp.resize(1<<N, vl(N, -1));
    dist.resize(N, vl(N, INF));
    times.resize(N, vl(N, INF));
    path.resize(1<<N, vl(N, -1));
    rep (i, M) {
        ll s, t, d, ti;
        cin >> s >> t >> d >> ti;
        s--; t--;
        dist.at(s).at(t) = d;
        dist.at(t).at(s) = d;
        times.at(s).at(t) = ti;
        times.at(t).at(s) = ti;
    }

    rep (i, N) {
        if (dist.at(0).at(i) <= times.at(0).at(i)) {
            dp.at(1<<i).at(i) = dist.at(0).at(i);
            if (i != 0) path.at(1<<i).at(i) = 1;
        }
    }

    ll d;
    d = rec((1<<N)-1, 0);
    if (d == INF) cout << "IMPOSSIBLE" << endl;
    else cout << d << " " << path.at((1<<N)-1).at(0) << endl;
}