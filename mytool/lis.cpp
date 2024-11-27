#include <bits/stdc++.h>
using namespace std;

template <typename T>
long long lis_length(vector<T> &a) {
    int n = a.size(), ret = 0;
    vector<T> v(n, (ll)3e18);
    for(int i=0; i<n; ++i) {
        int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        v[idx] = a[i];
        ret = max(ret, idx+1);
    }
    return ret;
}
template <typename T>
long long dis_length(vector<T> &a) {
    vector<T> b = a;
    for(auto &x: b) x = -x;
    long long ret = lis_length(b);
    return ret;
}