#include<bits/stdc++.h>
using namespace std;

// return minimum index i where a[i] >= x, and its value a[i]
template<typename T>
pair<long long,T> lowbou(vector<T> &a, T x, bool ascending=true) {
    long long n = a.size();
    T l = -1, r = n;
    while (r - l > 1) {
        T m = (l + r) / 2;
        if(ascending) {
            if (a[m] >= x) r = m;
            else l = m;
        } else {
            if (a[m] <= x) r = m;
            else l = m;
        }
    }
    if (r != n) return make_pair(r, a[r]);
    else return make_pair(n, (T)3e18);
}
// return minimum index i where a[i] > x, and its value a[i]
template<typename T>
pair<long long,T> uppbou(vector<T> &a, T x, bool ascending=true) {
    long long n = a.size();
    T l = -1, r = n;
    while (r - l > 1) {
        T m = (l + r) / 2;
        if(ascending) {
            if (a[m] > x) r = m;
            else l = m;
        } else {
            if (a[m] < x) r = m;
            else l = m;
        }
    }
    if (r != n) return make_pair(r, a[r]);
    else return make_pair(n, (T)3e18);
}
// return maximum index i where a[i] <= x, and its value a[i]
template<typename T>
pair<long long,T> lowbou_r(vector<T> &a, T x, bool ascending=true) {
    long long l = -1, r = a.size();
    while (r - l > 1) {
        T m = (l + r) / 2;
        if(ascending) {
            if (a[m] <= x) l = m;
            else r = m;
        } else {
            if (a[m] >= x) l = m;
            else r = m;
        }
    }
    if (l != -1) return make_pair(l, a[l]);
    else return make_pair(-1, (T)-3e18);
}
// return maximum index i where a[i] < x, and its value a[i]
template<typename T>
pair<long long,T> uppbou_r(vector<T> &a, T x, bool ascending=true) {
    long long l = -1, r = a.size();
    while (r - l > 1) {
        T m = (l + r) / 2;
        if(ascending) {
            if (a[m] < x) l = m;
            else r = m;
        } else {
            if (a[m] > x) l = m;
            else r = m;
        }
    }
    if (l != -1) return make_pair(l, a[l]);
    else return make_pair(-1, (T)-3e18);
}
