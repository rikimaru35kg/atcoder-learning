#include <bits/stdc++.h>
using namespace std;

template <typename T> vector<T> cumsum(vector<T> &a) {
    int n = a.size();
    vector<T> ret(n+1);
    for(int i=0; i<n; ++i) ret[i+1] = ret[i] + a[i];
    return ret;
}
template <typename T> vector<T> cummul(vector<T> &a) {
    int n = a.size();
    vector<T> ret(n+1, T(1));
    for(int i=0; i<n; ++i) ret[i+1] = ret[i] * a[i];
    return ret;
}
template <typename T> vector<vector<T>> cumsum(vector<vector<T>> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<T>> ret(h+1, vector<T>(w+1));
    for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) ret[i+1][j+1] = a[i][j];
    for(int i=0; i<h; ++i) for(int j=0; j<w+1; ++j) ret[i+1][j] += ret[i][j];
    for(int i=0; i<h+1; ++i) for(int j=0; j<w; ++j) ret[i][j+1] += ret[i][j];
    return ret;
}
