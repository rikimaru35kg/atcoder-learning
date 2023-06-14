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
#define all(v) (v).begin(), (v).end()


struct Pos {
    ll i, j;
    Pos (ll xx = -1, ll yy = -1) {
        i = xx;
        j = yy;
    }
};

// vvb visited;
vvl dp;
vvc field;
vl di = {-1, 0, 1, 0};
vl dj = {0, -1, 0, 1};

bool movable(ll i, ll j) {
    ll H = field.size();
    ll W = field.at(0).size();
    if (i < 0 || i >= H) return false;
    if (j < 0 || j >= W) return false;
    if (field.at(i).at(j) == 'X') return false;
    if (dp.at(i).at(j) >= 0) return false;
    return true;
}

ll get_dist(ll si, ll sj, ll gi, ll gj) {
    queue<Pos> que;
    Pos p(si, sj);
    dp.at(si).at(sj) = 0;
    // visited.at(si).at(sj) = true;
    que.push(p);
    while(!que.empty()) {
        Pos t = que.front();
        que.pop();
        if (t.i == gi && t.j == gj) break;

        rep (k, 4) {
            ll ni = t.i + di.at(k);
            ll nj = t.j + dj.at(k);
            if (movable(ni, nj)) {
                dp.at(ni).at(nj) = dp.at(t.i).at(t.j) + 1;
                // visited.at(ni).at(nj) = true;
                Pos np(ni, nj);
                que.push(np);
            }
        }
    }

    return dp.at(gi).at(gj);
}

int main () {
    ll H, W, N; cin >> H >> W >> N;
    field.resize(H, vc(W));
    rep (i, H) rep (j, W) cin >> field.at(i).at(j);

    // visited.resize(H, vb(W, false));
    dp.resize(H, vl(W, -1));

    vector<Pos> factories(N);

    ll start_i, start_j;
    rep (i, H) rep (j, W) {
        // string s{field.at(i).at(j)};
        // if (regex_match(s, regex("[1-9]"))) {
        //     factories.at(stoi(s)-1).i = i;
        //     factories.at(stoi(s)-1).j = j;
        // } 
        // if (s == "S") {
        //     start_i = i;
        //     start_j = j;
        // }
        char c = field.at(i).at(j);
        if (c == 'S') {
            start_i = i;
            start_j = j;
        }
        else if (c - '0' >= 1 && c - '0' <= 9) {
            factories.at(c-'0'-1).i = i;
            factories.at(c-'0'-1).j = j;
        }

    }

    ll dist = 0;
    rep (k, N) {
        ll si, sj, gi, gj;
        if (k == 0) {
            si = start_i;
            sj = start_j;
            gi = factories.at(k).i;
            gj = factories.at(k).j;
        }
        else {
            si = factories.at(k-1).i;
            sj = factories.at(k-1).j;
            gi = factories.at(k).i;
            gj = factories.at(k).j;
        }

        dp.assign(H, vl(W, -1));
        // visited.assign(H, vb(W, false));
        dist += get_dist(si, sj, gi, gj);

    }

    cout << dist << endl;
}