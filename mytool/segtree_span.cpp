#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vp = vector<pair<ll,ll>>;

vp spans;

void get_spans1(ll l, ll r) {
    ll N = 1LL<<60;  // segtree size = N*2;
    ll lv = l + N, rv = r + N;  // vertex id for segtree(1-indexed)
    ll w = 1; // current span
    while(l < r) {
        if(lv%2==1) {  // use this
            spans.emplace_back(l, l+w);
            ++lv;
            l += w;
        }
        lv /= 2;
        if(rv%2==1) {  // use this
            spans.emplace_back(r-w, r);
            --rv;
            r -= w;
        }
        rv /= 2;
        w <<= 1;
    }
    sort(spans.begin(), spans.end());
}

// l, r: query span
// cl, cr: currently judging spans
// v: vertex id
vector<ll> vs;
void get_spans2(ll l, ll r, ll cl=0, ll cr=(1LL<<60), ll v=1) {
    if(r <= cl) return;
    if(l >= cr) return;
    if(cl >= l && cr <= r) {
        spans.emplace_back(cl, cr);
        vs.push_back(v);
        return;
    }
    ll m = (cl + cr) / 2;
    if(l < m) get_spans2(l, r, cl, m, 2*v);
    if(r > m) get_spans2(l, r, m, cr, 2*v+1);
}

int main () {
    cin.tie(nullptr);
    ll l, r;  // span
    cin >> l >> r;
    printf("span1 result\n");
    get_spans1(l, r);
    for(auto [l, r]: spans) {
        printf("%lld %lld\n", l, r);
    }

    printf("span2 result\n");
    spans = vp();
    get_spans2(l, r, 0, 8);
    sort(spans.begin(), spans.end());
    for(auto [l, r]: spans) {
        printf("%lld %lld\n", l, r);
    }
    sort(vs.begin(), vs.end());
    for(auto v: vs) printf("%lld ", v);
    cout<<endl;
}

