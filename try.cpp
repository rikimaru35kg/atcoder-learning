#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

struct Edge {
  int to, c;
  Edge(int to, int c): to(to), c(c) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(i,m) {
    int a, b; char c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b, c-'a');
    g[b].emplace_back(a, c-'a');
  }
  const int INF = 1001001001;
  vector<vector<int>> dp(n, vector<int>(n, INF));
  queue<P> q;
  auto push = [&](int a, int b, int x) {
    if (dp[a][b] != INF) return;
    dp[a][b] = x;
    q.emplace(a,b);
  };
  push(0,n-1,0);
  while (!q.empty()) {
    auto [a, b] = q.front(); q.pop();
    for (auto ea : g[a]) for (auto eb : g[b]) {
      if (ea.c != eb.c) continue;
      push(ea.to, eb.to, dp[a][b]+1);
    }
  }
  int ans = INF;
  rep(i,n) {
    ans = min(ans, dp[i][i]*2);
    for (auto e : g[i]) {
      ans = min(ans, dp[i][e.to]*2+1);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}