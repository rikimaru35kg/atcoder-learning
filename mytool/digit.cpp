#include<bits/stdc++.h>
using namespace std;

vector<long long> separate_digit(long long x, long long base=10, long long sz=-1) {
    vector<long long> ret;
    if(x==0) ret.push_back(0);
    while(x) {
        ret.push_back(x%base);
        x /= base;
    }
    if(sz!=-1) {
        while((long long)ret.size()<sz) ret.push_back(0); // sz桁になるまで上桁を0埋め
        while((long long)ret.size()>sz) ret.pop_back(); // 下sz桁を取り出す
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