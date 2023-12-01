#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

#define XOR

#ifdef XOR
ll op(ll x, ll y){ return x^y;}
ll e(){return 0;}
// segtree<ll,op,e> seg(N);
// seg.set(i, x^seg.get(i));
// seg.prod(l, r);
#endif

int main () {
#ifdef XOR
    segtree<ll,op,e> seg(10);
    seg.set(0, 5);
    seg.set(1, 1);
    seg.set(2, 3);
    cout << seg.prod(0, 3) << endl;;
    seg.set(1, 1^seg.get(1));
    cout << seg.prod(0, 3) << endl;;
#endif

}

