#include <bits/stdc++.h>
using namespace std;

/* BIT: RAQ対応BIT
    初期値は a_0 = a_1 = ... = a_n-1 = 0
    ・add(i, x): a_i に x を加算する
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_0 + a_1 + ... + a_i-1 を計算する
    計算量は全て O(logn)
    内部的には1-indexedだが、外部から使うときは0-indexedでOK
*/
template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        ++l; ++r;  // 0-indexed --> 1-indexed
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    void add1(int i, T x) {  // 要素iにxを加算
        add(i, i+1, x);
    }
    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) {
        ++i;  // 0-indexed --> 1-indexed
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }
};

int main () {
    BIT<long long> bit(10);
    bit.add(1, 2, 5);
    bit.add(3, 5, 6);
    cout << bit.sum(3) << endl;
    cout << bit.sum(6) << endl;
    cout << bit.sum(9) << endl;
    bit.add(9, 10, 3);
    cout << bit.sum(9) << endl;
    bit.add(0, 10, -10);
    cout << bit.sum(9) << endl;
    bit.add1(0, 100);
    cout << bit.sum(0) << endl;

}