#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct UnionFind {
    vector<T> p;
    vector<T> num;
    UnionFind(T n) : p(n, -1), num(n, 1) {}

    T find (T x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    void unite (T x, T y) {
        x = find(x); y = find(y);
        if (x == y) return;
        p[x] = y;
        num[y] += num[x];
    }
    bool same (T x, T y) {
        return find(x) == find(y);
    }
    T size (T x) {
        return num[find(x)];
    }
};

int main () {
    UnionFind<long long> uf(100);
    uf.unite(5, 10);
    uf.unite(10, 15);
    cout << uf.same(5, 15) << endl;
    cout << uf.size(10) << endl;
    cout << uf.size(5) << endl;
    cout << uf.size(15) << endl;
    uf.unite(6, 99);
    cout << uf.size(6) << endl;
    cout << uf.size(99) << endl;
    cout << uf.size(50) << endl;
}