#include<bits/stdc++.h>
using namespace std;

vector<long long> separate_digit(long long x, long long base=10) {
    vector<long long> ret;
    while(x) {
        ret.push_back(x%base);
        x /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

long long consolidate_digit(vector<long long> a, long long base=10) {
    long long ret = 0;
    for(auto x: a) {
        ret = ret*base + x;
    }
    return ret;
}
