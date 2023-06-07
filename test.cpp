#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define repr(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (int i = k; i < (int)(n); i++)

ll modpower(ll a, ll b, ll mod) {
    // Calculate mod(a^b, mod)
    // a >= 0, b >= 0, mod > 0;
	ll ans = 1;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}

struct State {
    ll r, c, dist;
    vvb visited;

    State(ll H, ll W) {
        visited.resize(H, vb(W, false));
    }

};

bool movable(ll r, ll c, vvc &tmap) {
    if (r >= tmap.size() || r < 0) return false;
    if (c >= tmap.at(0).size() || c < 0) return false;
    if (tmap.at(r).at(c) == '#') return false;

    return true;
}

vl dr = {-1, 0, 1, 0};
vl dc = {0, 1, 0, -1};

vvl used;

ll dfs(ll r0, ll c0, ll r1, ll c1, vvc &tmap) {
    if (r0 == r1 && c0 == c1) {
        if (used.at(r0).at(c0)) return 0;
    }

    used.at(r1).at(c1) = true;
    ll dist_max = -1;
    rep (i, 4) {
        ll r2 = r1 + dr.at(i);
        ll c2 = c1 + dc.at(i);
        if (movable(r2, c2, tmap) || (r0 == r2 && c0 == c2)) {
            if (used.at(r2).at(c2) && (r0 != r2 || c0 != c2)) continue;
            ll v = dfs(r0, c0, r2, c2, tmap);
            if (v >= 0) dist_max = max(dist_max, v + 1);
        }
    }

    used.at(r1).at(c1) = false;
    return dist_max;
}

int main() {
    ll H, W; cin >> H >> W;
    vvc c(H, vc(W));
    rep (i, H) rep (j, W) cin >> c.at(i).at(j);

    used.resize(H, vl(W, false));

    ll dist_max = -1;
    rep (i, H) {
        rep (j, W) {
            if (c.at(i).at(j) == '#') continue;
            dist_max = max(dist_max, dfs(i, j, i, j, c));
        }
    }

    if (dist_max > 0) cout << dist_max << endl;
    else cout << "-1" << endl;
}
