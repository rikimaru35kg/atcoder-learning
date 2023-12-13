#include <bits/stdc++.h>
using namespace std;

//! n*n matrix
//! Currently, only operator* is defined.
template <typename T>
class Mat {
    long long n; vector<vector<T>> a;
public:
    // Initialize n*n matrix
    Mat (long long n, const vector<vector<T>> &mat={}): n(n), a(n, vector<T>(n)) {
        // unit matrix if mat is not specified
        if (mat.size() == 0) for (int i=0; i<n; ++i) a[i][i] = 1;
        else {
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
                a[i][j] = mat[i][j];
            }
        }
    }
    // Define operator*
    Mat operator* (const Mat &rhs) {  // Mat * Mat
        Mat ret(n);
        ret.a.assign(n, vector<T>(n, 0));  // zero matrix
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) ret.a[i][j] += a[i][k] * rhs.a[k][j];
        }
        return ret;
    }
    vector<T> operator* (const vector<T> &rhs) {  // Mat * vector
        vector<T> ret(n, 0);
        for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) {
            ret[j] += a[j][k] * rhs[k];
        }
        return ret;
    }
#ifdef __DEBUG
    void print(string debugname="------") {  // for debug
        cerr << debugname << ":\n";
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            cerr << a[i][j] << (j==2? '\n': ' ');
        }
        cerr << "---------" << '\n';
    }
#else
    void print(string debugname) {}
#endif
};
