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
