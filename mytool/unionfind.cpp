#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<long long> p, num;
    UnionFind(long long n) : p(n, -1), num(n, 1) {}

    long long leader (long long x) {
        if (p[x] == -1) return x;
        return p[x] = leader(p[x]);
    }
    void merge (long long x, long long y) {
        x = leader(x); y = leader(y);
        if (x == y) return;
        if (size(x) > size(y)) swap(x, y); // new parent = y
        p[x] = y;
        num[y] += num[x];
    }
    bool same (long long x, long long y) {
        return leader(x) == leader(y);
    }
    long long size (long long x) {
        return num[leader(x)];
    }
};

struct WeightedUnionFind {
    vector<long long> p, num, diff;
    WeightedUnionFind(long long n) : p(n,-1), num(n,1), diff(n,0) {}
    long long leader (long long x) {
        if (p[x] == -1) return x;
        long long y = p[x];
        p[x] = leader(y);
        diff[x] += diff[y];
        return p[x];
    }
    bool merge (long long x, long long y, long long w=0) {   // x - y = w
        leader(x); leader(y);  // path compression, -> diff will be based on root.
        w = diff[y] - diff[x] - w;  // p[x]->x->y->p[y]
        x = leader(x); y = leader(y);
        if (x == y) return w == 0;
        if (size(x) > size(y)) swap(x, y), w = -w; // new parent = y
        diff[x] = w;
        p[x] = y;
        num[y] += num[x];
        return true;
        // merge関数はポテンシャルの差として引数を指定すれば良い
        // yに対してxのポテンシャルはw大きい
        // なお、diffは自分の親に対してのポテンシャル増加分を表すので
        // diffが正であるとは、親よりもポテンシャルが低いという事
        // （親ベースの増加分ではなく、それにマイナスをかけたもの）
        // 従ってvのuに対するポテンシャルを求めたいのであれば
        // diff[u]-diff[v]となる事に注意（感覚的には逆と思えてしまう）
    }
    bool same (long long x, long long y) { return leader(x) == leader(y); }
    long long size (long long x) { return num[leader(x)]; }
};


int main () {
    UnionFind uf(100);
    uf.merge(5, 10);
    uf.merge(10, 15);
    cout << uf.same(5, 15) << endl;
    cout << uf.size(10) << endl;
    cout << uf.size(5) << endl;
    cout << uf.size(15) << endl;
    uf.merge(6, 99);
    cout << uf.size(6) << endl;
    cout << uf.size(99) << endl;
    cout << uf.size(50) << endl;
}