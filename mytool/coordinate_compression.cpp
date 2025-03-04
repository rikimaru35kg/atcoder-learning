#include<bits/stdc++.h>
using namespace std;

template <typename T>
class CoordinateCompression {
    bool oneindexed, init = false;
    vector<T> vec;
public:
    CoordinateCompression(bool one=false): oneindexed(one) {}
    void add (T x) {vec.push_back(x);}
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        init = true;
    }
    long long operator() (T x) {
        if (!init) compress();
        long long ret = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        if (oneindexed) ++ret;
        return ret;
    }
    T operator[] (long long i) {
        if (!init) compress();
        if (oneindexed) --i;
        if (i < 0 || i >= (long long)vec.size()) return T();
        return vec[i];
    }
    long long size () {
        if (!init) compress();
        return (long long)vec.size();
    }
    void print() {
        #ifdef __DEBUG
        printf("---- cc print ----\ni: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", i);
        printf("\nx: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", vec[i]);
        printf("\n-----------------\n");
        #endif
    }
};