#include<bits/stdc++.h>
using namespace std;

template<typename T> void unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
