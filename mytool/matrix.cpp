#include <bits/stdc++.h>
using namespace std;

// Vector
const double eps = 1e-8; // suppose max(x,y) <= 1e9;
struct Vec {
    double x, y;
    Vec(double x=0, double y=0): x(x), y(y) {}
    Vec& operator+=(const Vec& v) { x += v.x; y += v.y; return *this;}
    Vec operator+(const Vec& v) const { return Vec(*this) += v;}
    Vec& operator-=(const Vec& v) { x -= v.x; y -= v.y; return *this;}
    Vec operator-(const Vec& v) const { return Vec(*this) -= v;}
    Vec& operator*=(double s) { x *= s; y *= s; return *this;}
    Vec operator*(double s) const { return Vec(*this) *= s;}
    Vec& operator/=(double s) { x /= s; y /= s; return *this;}
    Vec operator/(double s) const { return Vec(*this) /= s;}
    double dot(const Vec& v) const { return x*v.x + y*v.y;}
    // cross>0 means *this->v is counterclockwise.
    double cross(const Vec& v) const { return x*v.y - v.x*y;}
    double norm2() const { return x*x + y*y;}
    double norm() const { return sqrt(norm2());}
    Vec normalize() const { return *this/norm();}
    Vec rotate90() const { return Vec(y, -x);}
    int ort() const { // orthant
    if (abs(x) < eps && abs(y) < eps) return 0;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
    }
    bool operator<(const Vec& v) const {
      int o = ort(), vo = v.ort();
      if (o != vo) return o < vo;
      return cross(v) > 0;
    }
};
istream& operator>>(istream& is, Vec& v) {
    is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const Vec& v) {
    os<<"("<<v.x<<","<<v.y<<")"; return os;
}

//! n*n matrix
//! Currently, only operator* is defined.
template <typename T>
class Mat {
    long long n; vector<vector<T>> a;
public:
    // Initialize n*n matrix
    Mat (long long n, const vector<vector<T>> &mat={})
    : n(n), a(n, vector<T>(n)) {
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
            for (int k=0; k<n; ++k) {
                ret.a[i][j] += a[i][k] * rhs.a[k][j];
            }
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
    // power k (A^k)
    void pow(long long k) {
        *this = pow_recursive(*this, k);
    }
    Mat pow_recursive(Mat b, long long k) {
        Mat ret(b.n);
        if (k == 0) return ret;
        if (k%2 == 1) ret = b;
        Mat tmp = pow_recursive(b, k/2);
        return ret * tmp * tmp;
    }
    long long ij(long long i, long long j) {
        return a[i][j];
    }
#ifdef __DEBUG
    void print(string debugname="------") {  // for debug
        cerr << n << '\n';
        cerr << debugname << ":\n";
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            cerr << a[i][j] << (j==n-1? '\n': ' ');
        }
        cerr << "---------" << '\n';
    }
#else
    void print(string debugname="------") {}
#endif
};

//! n*n matrix
//! Currently, only operator* is defined.
template <typename T>
class Mat_OLD {
    long long n; vector<vector<T>> a; long long mod;
public:
    // Initialize n*n matrix
    Mat (long long n, const vector<vector<T>> &mat={}, long long mod=-1)
    : n(n), a(n, vector<T>(n)), mod(mod) {
        // unit matrix if mat is not specified
        if (mat.size() == 0) for (int i=0; i<n; ++i) a[i][i] = 1;
        else {
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
                a[i][j] = mat[i][j];
                if (mod != -1) a[i][j] %= mod;
            }
        }
    }
    // Define operator*
    Mat operator* (const Mat &rhs) {  // Mat * Mat
        Mat ret(n);
        if (mod != -1) ret = Mat(n, ret.a, mod);
        ret.a.assign(n, vector<T>(n, 0));  // zero matrix
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                ret.a[i][j] += a[i][k] * rhs.a[k][j];
                if (mod != -1) ret.a[i][j] %= mod;
            }
        }
        return ret;
    }
    vector<T> operator* (const vector<T> &rhs) {  // Mat * vector
        vector<T> ret(n, 0);
        for (int j=0; j<n; ++j) for (int k=0; k<n; ++k) {
            ret[j] += a[j][k] * rhs[k];
            if (mod != -1) ret[j] %= mod;
        }
        return ret;
    }
    // power k (A^k)
    Mat pow(long long k) {
        Mat ret = pow_recursive(*this, k);
        return ret;
    }
    Mat pow_recursive(Mat b, long long k) {
        Mat ret(n);
        if (mod != -1) ret = Mat(n, ret.a, mod);
        if (k == 0) return ret;
        if (k%2 == 1) ret = b;
        Mat tmp = pow_recursive(b, k/2);
        return ret * tmp * tmp;
    }
    long long ij(long long i, long long j) {
        return a[i][j];
    }
#ifdef __DEBUG
    void print(string debugname="------") {  // for debug
        cerr << n << '\n';
        cerr << debugname << ":\n";
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            cerr << a[i][j] << (j==n-1? '\n': ' ');
        }
        cerr << "---------" << '\n';
    }
#else
    void print(string debugname="------") {}
#endif
};
