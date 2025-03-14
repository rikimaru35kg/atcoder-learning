#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> make_next(string &s, char base='a') {
    int n = s.size(), Z = 26;
    vector<vector<int>> next(Z, vector<int>(n, n));
    for(int i=0; i<n; ++i) next[s[i]-base][i] = i;
    for(int z=0; z<Z; ++z) for(int i=n-2; i>=0; --i) {
        next[z][i] = min(next[z][i], next[z][i+1]);
    }
    return next;
}
template <typename T>
vector<vector<int>> make_next(vector<T> a, int mx) {
    int n = a.size();
    vector<vector<int>> next(mx, vector<int>(n, n));
    for(int i=0; i<n; ++i) next[a[i]][i] = i;
    for(int z=0; z<mx; ++z) for(int i=n-2; i>=0; --i) {
        next[z][i] = min(next[z][i], next[z][i+1]);
    }
    return next;
}
// return next position + 1
// if ret>n, then no valid position
int find_next(vector<int> &nxt, int i) {
    int n = nxt.size();
    if(i>=n) return n+1;
    return nxt[i]+1;  // return next position
}