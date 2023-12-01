#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
// #define RAQ_RMINQ
//#define RAQ_RMAXQ
// #define RAQ_RSQ
//#define RUQ_RMINQ
//#define RUQ_RMAXQ
//#define RUQ_RSQ
#define RMINUQ_RMINQ

// Sはモノイド（各マスのイメージ）の元の型。mapping Fを定義する際に幅がないとFで更新できないので、区間加算などの時はstructにする
// opはモノイド同士の演算
// e()は単位元を返す関数
// Fは写像を定義する為に必要な型（単に数字を足すだけならintで良い）。例えばf(S)=S+10という写像があったとすると、fは10で定義されるので、Fの方はintで良い
// mappingはSにFを適用させる関数。
// compositionはfとgの合成関数を定義する。
// id()は恒等写像、すなわち値を変化させない写像を定義する

// 区間最小更新・区間最小値取得（RMUQ+RMQ）=========================
#ifdef RMINUQ_RMINQ
using S = long long;
const S UNIT = 8e18;
S op (S a, S b) {return min(a, b);}
S e() {return UNIT;}
using F = long long;
S mapping (F f, S x) {return min(f, x);}
F composition (F f, F g) {return min(f, g);}
F id() {return UNIT;}

#endif
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
// 書き方例
// vector<S> v(N);
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
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
// 書き方例
// vector<S> v(N);
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
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
// 書き方例
// vector<S> v(N, {0, 1});
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
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
// 書き方例
// vector<S> v(N);
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
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
// 書き方例
// vector<S> v(N);
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
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
// 書き方例
// vector<S> v(N, {0, 1});
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
#endif
// =========================================================

int main(){
    int N = 1e6;
    // lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    // seg.apply(10, 20, 5);  // [10,20)に5を適用（加算or更新）
    // long long x = seg.prod(11, 15);  // [11,15)の区間演算（min or max or sum）
#ifdef RAQ_RSQ
    vector<S> v(N, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    seg.apply(10, 20, 5);  // [10,20)に5を適用（加算or更新）
    long long x = seg.prod(11, 50).value;
    cout << x << endl;
#endif
#ifdef RMINUQ_RMINQ
    lazy_segtree<S,op,e,F,mapping,composition,id> seg(N);
    seg.apply(0, 5, 3);
    seg.apply(2, 8, 10);
    for (int i=0; i<10; ++i) {
        printf("%d %lld\n", i, seg.prod(i, i+1));
    }
#endif

}
