#include<bits/stdc++.h>
using namespace std;

// return minimum index i where a[i] >= x, and its value a[i]
// vector a must be pre-sorted in ascending (normal) order!
// return value of a.size() means a.back() is not over x (a.back()<x)
pair<long long,long long> lowbou(vector<long long> &a, long long x) {
    long long n = a.size();
    long long l = -1, r = n;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (a[m] >= x) r = m;
        else l = m;
    }
    if (r != n) return make_pair(r, a[r]);
    else return make_pair(n, (long long)3e8);
}
// return minimum index i where a[i] > x, and its value a[i]
// vector a must be pre-sorted in ascending (normal) order!
// return value of a.size() means a.back() is not over x (a.back()<=x)
pair<long long,long long> uppbou(vector<long long> &a, long long x) {
    long long n = a.size();
    long long l = -1, r = n;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (a[m] > x) r = m;
        else l = m;
    }
    if (r != n) return make_pair(r, a[r]);
    else return make_pair(n, (long long)3e8);
}

// return maximum index i where a[i] <= x, and its value a[i]
// vector a must be pre-sorted in ascending (normal) order!
// return value of -1 means a[0] is already over x (a[0]>x)
pair<long long,long long> lowbou_r(vector<long long> &a, long long x) {
    long long l = -1, r = a.size();
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    if (l != -1) return make_pair(l, a[l]);
    else return make_pair(-1, (long long)-3e8);
}

// return maximum index i where a[i] < x, and its value a[i]
// vector a must be pre-sorted in ascending (normal) order!
// return value of -1 means a[0] is already over x (a[0]>=x)
pair<long long,long long> uppbou_r(vector<long long> &a, long long x) {
    long long l = -1, r = a.size();
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (a[m] < x) l = m;
        else r = m;
    }
    if (l != -1) return make_pair(l, a[l]);
    else return make_pair(-1, (long long)-3e8);
}

int main () {
    vector<long long> A = {-3, 2, 0, 5, 10, 15, 10000};
    // auto [i1, x1] = lowbou(A, 10);
    // auto [i2, x2] = uppbou(A, 10);
    // auto [i3, x3] = lowbou_r(A, 10);
    // auto [i4, x4] = uppbou_r(A, 10);
    // cout << i1 << ' ' << x1 << endl;
    // cout << i2 << ' ' << x2 << endl;
    // cout << i3 << ' ' << x3 << endl;
    // cout << i4 << ' ' << x4 << endl;
    auto [i1, x1] = lowbou_r(A, -3);
    auto [i2, x2] = uppbou_r(A, -3);
    auto [i3, x3] = lowbou(A, 10000);
    auto [i4, x4] = uppbou(A, 10000);
    cout << i1 << ' ' << x1 << endl;
    cout << i2 << ' ' << x2 << endl;
    cout << i3 << ' ' << x3 << endl;
    cout << i4 << ' ' << x4 << endl;
}