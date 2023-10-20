#include<bits/stdc++.h>
using namespace std;

class CoordinateCompression {
    vector<long long> vec;
public:
    void add (long long x) {
        vec.push_back(x);
    }
    void compress () {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    long long get (long long x) {
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    }
    long long get_back (long long i) {
        if (i >= SIZE(vec)) return 3e18;
        return vec[i];
    }
    long long size () {
        return SIZE(vec);
    }
};
