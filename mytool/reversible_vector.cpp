#include <bits/stdc++.h>
using namespace std;

template <class S>
struct ReversibleVector {
    struct xorshift {
        using u32 = uint32_t;
        u32 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        xorshift(u32 seed = 0) { z ^= seed; }
        u32 operator()() {
            u32 t = x ^ (x << 11);
            x = y;
            y = z;
            z = w;
            return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        }
    };
    xorshift rnd;
    struct Node {
        S val;
        int pri, cnt;
        bool rev;
        Node *l, *r;
        Node(S val_, int pri_) : val(val_), pri(pri_), cnt(1), rev(false), l(nullptr), r(nullptr) {}
    } *root = nullptr;
    using tree = Node *;
    int count(tree t) { return t ? t->cnt : 0; }
    void proc(tree &t) { if(t) t->cnt = 1 + count(t->l) + count(t->r); }
    void eval(tree &t) {
        if(t and t->rev) {
            t->rev = false;
            std::swap(t->l, t->r);
            if(t->l) t->l->rev ^= 1;
            if(t->r) t->r->rev ^= 1;
        }
        proc(t);
    }
    void split(tree t, int key, tree &l, tree &r) {
        if(!t) {
            l = r = nullptr;
            return;
        }
        eval(t);
        int imp_key = count(t->l) + 1;
        if(key < imp_key) {
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key - imp_key, t->r, r), l = t;
        }
        proc(t);
    }
    void merge(tree &t, tree &l, tree &r) {
        eval(l);
        eval(r);
        if(!l or !r) t = l ? l : r;
        else if(l->pri > r->pri) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
        proc(t);
    }
    void insert(tree &t, int key, tree item) {
        tree t1, t2;
        split(t, key, t1, t2);
        merge(t1, t1, item);
        merge(t, t1, t2);
    }
    void erase(tree &t, int key) {
        tree t1, t2, t3;
        split(t, key + 1, t1, t2);
        split(t1, key, t1, t3);
        merge(t, t1, t2);
    }
    void reverse(tree t, int l, int r) {
        if(l > r) return;
        tree t1, t2, t3;
        split(t, l, t1, t2);
        split(t2, r - l, t2, t3);
        t2->rev ^= 1;
        merge(t2, t2, t3);
        merge(t, t1, t2);
    }
    void rotate(tree t, int l, int m, int r) {
        reverse(t, l, r);
        reverse(t, l, l + r - m);
        reverse(t, l + r - m, r);
    }
   public:
    ReversibleVector() {}
    ReversibleVector(std::vector<S> as) {
        std::reverse(as.begin(), as.end());
        for(S &a : as) { insert(0, a); }
    }
    ReversibleVector(std::string as) {
        std::reverse(as.begin(), as.end());
        for(S &a : as) { insert(0, a); }
    }
    int size() { return count(root); }
    void insert(int pos, S x) { insert(root, pos, new Node(x, rnd())); }
    void erase(int pos) { erase(root, pos); }
    void reverse(int l, int r) { reverse(root, l, r); }
    void rotate(int l, int m, int r) { rotate(root, l, m, r); }
    void push_back(S x) { insert(size(), x); }
    void push_front(S x) { insert(0, x); }
    void pop_back() {
        assert(size());
        erase(size() - 1);
    }
    void pop_front() {
        assert(size());
        erase(0);
    }
    S &operator[](int pos) {
        tree t1, t2, t3;
        split(root, pos + 1, t1, t2);
        split(t1, pos, t1, t3);
        S &ret = t3->val;
        merge(t1, t1, t3);
        merge(root, t1, t2);
        return ret;
    }
};

int main() {
    ReversibleVector<int> vec;
    return 0;
}