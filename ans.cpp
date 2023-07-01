#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll wa = -1, ac = 2e9;
  auto f = [&](ll x) {
    ll res = 0;
    rep(i,n) res += max(0ll, a[i]-x);
    return res;
  };
  while (wa+1<ac) {
    int wj = (wa+ac)/2;
    if (f(wj) <= k) ac = wj; else wa = wj;
  }
  ll ans = 0;
  auto asum = [&](ll l, ll r) {
    return (l+r)*(r-l+1)/2;
  };
  rep(i,n) {
    if (a[i] <= ac) continue;
    ans += asum(ac+1, a[i]);
  }
  ans += ac*(k-f(ac));
  cout << ans << endl;
  return 0;
}