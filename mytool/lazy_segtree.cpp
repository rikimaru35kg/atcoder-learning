#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define RAQ_RMINQ
//#define RAQ_RMAXQ
//#define RAQ_RSQ
//#define RUQ_RMINQ
//#define RUQ_RMAXQ
//#define RUQ_RSQ

// 区間加算・区間最小値取得（RAQ+RMINQ）=========================
#ifdef RAQ_RMINQ
using S = long long;
using F = long long;

const S UNIT = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return UNIT; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
#endif
// 区間加算・区間最大値取得（RAQ+RMAXQ）=========================
#ifdef RAQ_RMAXQ
using S = long long;
using F = long long;

const S UNIT = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -UNIT; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
#endif
// 区間加算・区間和取得（RAQ+RSQ）=========================
#ifdef RAQ_RSQ
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
// seg.prod(l, r).valueで値を取り出す
#endif
// 区間更新・区間最小値取得（RUQ+RMINQ）=========================
#ifdef RUQ_RMINQ
using S = long long;
using F = long long;

const S UNIT = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return UNIT; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
#endif
// 区間更新・区間最大値取得（RUQ+RMAXQ）=========================
#ifdef RUQ_RMAXQ
using S = long long;
using F = long long;

const S UNIT = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -UNIT; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
#endif
// 区間更新・区間和取得（RUQ+RSQ）=========================
#ifdef RUQ_RSQ
struct S{
    long long value;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
// seg.prod(l, r).valueで値を取り出す
#endif
// =========================================================

int main(){
    int N = 1e6;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    seg.apply(10, 20, 5);  // [10,20)に5を適用（加算or更新）
    long long x = seg.prod(11, 15);  // [11,15)の区間演算（min or max or sum）
}
