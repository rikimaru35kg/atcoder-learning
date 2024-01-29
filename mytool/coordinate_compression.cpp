#include<bits/stdc++.h>
using namespace std;

class CoordinateCompression {
    bool oneindexed, init = false;
    vector<long long> vec;
public:
    CoordinateCompression(bool one=false): oneindexed(one) {}
    void add (long long x) {vec.push_back(x);}
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        init = true;
    }
    long long operator() (long long x) {
        if (!init) compress();
        long long ret = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        if (oneindexed) ++ret;
        return ret;
    }
    long long operator[] (long long i) {
        if (!init) compress();
        if (oneindexed) --i;
        if (i < 0 || i >= (long long)vec.size()) return 3e18;
        return vec[i];
    }
    long long size () {return (long long)vec.size();}
#ifdef __DEBUG
    void print() {
        printf("---- cc print ----\ni: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", i);
        printf("\nx: ");
        for (long long i=0; i<(long long)vec.size(); ++i) printf("%2lld ", vec[i]);
        printf("\n-----------------\n");
    }
#else
    void print() {}
#endif
};