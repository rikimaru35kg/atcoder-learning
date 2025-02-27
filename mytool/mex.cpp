#include <bits/stdc++.h>
using namespace std;

long long calmex(vector<long long> &x) {
    long long N = SIZE(x);
    vector<bool> used(N);
    for(long long i=0; i<N; ++i) if(x[i]<N) used[x[i]] = true;
    long long ret = 0;
    while(ret<N && used[ret]) ++ret;
    return ret;
};

// O(log(N)) for each operation
struct OnlineMex {
    int n;  // the maximum numbers possible to be input
    set<int> rems;
    vector<int> cnt;
    OnlineMex(int n): n(n), cnt(n+1) {
        for(int i=0; i<=n; ++i) rems.insert(i);
    }
    void add(long long x, int c=1) {
        if(x>n) return;
        rems.insert(x);
        cnt[x] += c;
        if(cnt[x]>0) rems.erase(x);
        assert(cnt[x]>=0);
    }
    void del(int x) {add(x,-1);}
    int get_mex() {
        assert(!rems.empty());
        return *rems.begin();
    }
};