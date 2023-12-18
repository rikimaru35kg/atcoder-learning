#include<bits/stdc++.h>
using namespace std;

class CoordinateCompression {
    vector<long long> vec;
public:
    void add (long long x) {vec.push_back(x);}
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    long long get (long long x) {
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    }
    long long get_back (long long i) {
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
