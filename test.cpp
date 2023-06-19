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

ll N, M, K, S;
ll P, Q;
vl C;
vb zonb;
vvl edge;
vb danger;
vb visited;
vl cost;

void dfs(ll p, ll dist) {
    visited.at(p) = true;
    for (auto x: edge.at(p)) {
        if (!visited.at(x) && dist <= S && !zonb.at(x)) {
            danger.at(x) = true;
            dfs(x, dist+1);
        }
    }
    visited.at(p) = false;
}

void bfs(vl &C) {
    queue<ll> que;
    vl safety(N, INF);
    for (auto x: C) {
        que.push(x);
        safety.at(x) = 0;
        danger.at(x) = true;
    }
    while(!que.empty()) {
        ll t = que.front(); que.pop();
        for (auto x: edge.at(t)) {
            if (safety.at(x) > safety.at(t) + 1) {
                safety.at(x) = safety.at(t) + 1;
                if (safety.at(x) <= S) {
                    danger.at(x) = true;
                    que.push(x);
                }
            }
        }
    }
}

void dijk(ll start) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    cost.at(start) = 0;
    pque.push({0, start});
    while(!pque.empty()) {
        Pair t = pque.top(); pque.pop();
        ll c = t.first;
        ll n = t.second;
        if (cost.at(n) < c) continue;

        for (auto x: edge.at(n)) {
            ll n_cost;
            if (zonb.at(x)) continue;
            if (x == N-1) n_cost = 0;
            else if (danger.at(x)) n_cost = Q;
            else n_cost = P;
            if (n_cost + cost.at(n) < cost.at(x)) {
                cost.at(x) = n_cost + cost.at(n);
                pque.push({cost.at(x), x});
            }
        }
    }
}

int main () {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    edge.resize(N);
    cost.resize(N, INF);
    visited.resize(N, false);
    zonb.resize(N, false);
    danger.resize(N, false);
    rep (i, K) {
        ll c; cin >> c; c--;
        zonb.at(c) = true;
        C.push_back(c);
    }
    rep (i, M) {
        ll a, b; cin >> a >> b; a--; b--;
        edge.at(a).push_back(b);
        edge.at(b).push_back(a);
    }

    // for (auto x: C) {
    //     dfs(x, 1);
    // }

    bfs(C);

    dijk(0);

    cout << cost.at(N-1) << endl;

}