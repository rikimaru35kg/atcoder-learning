#include<bits/stdc++.h>
using namespace std;

struct BidirectionalList {
    const long long ninf = (long long)3e18;
    unordered_map<long long,pair<long long,long long>> mp;
    BidirectionalList () {
        mp[-ninf] = {-ninf, ninf}; mp[ninf] = {-ninf, ninf};
    }
    void add_next(long long x, long long y) {  // put y after x
        auto [p, n] = mp[x];
        mp[x].second = y; mp[n].first = y;
        mp[y] = {x, n};
    }
    void add_prev(long long x, long long y) {  // put y before x
        auto [p, n] = mp[x];
        mp[x].first = y; mp[p].second = y;
        mp[y] = {p, x};
    }
    void add_head(long long x) { add_next(-ninf, x); }
    void add_tail(long long x) { add_prev(ninf, x); }
    void erase(long long x) {
        auto [p, n] = mp[x];
        mp[p].second = n; mp[n].first = p;
        mp.erase(x);
    }
    pair<long long,long long> get(long long x) { return mp[x]; }
    void print() {
        long long next = mp[-ninf].second;
        vector<long long> vec;
        while (next != ninf) {
            vec.push_back(next);
            next = mp[next].second;
        }
        for (int i=0; i<SIZE(vec); ++i) {
            cout << vec[i] << (i==SIZE(vec)-1?'\n':' ');
        }
    }
};
