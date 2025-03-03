#include <bits/stdc++.h>
using namespace std;

struct Vecll {
    long long x, y;
    Vecll(long long x=0, long long y=0): x(x), y(y) {}
    Vecll& operator+=(const Vecll &o) { x += o.x; y += o.y; return *this; }
    Vecll operator+(const Vecll &o) const { return Vecll(*this) += o; }
    Vecll& operator-=(const Vecll &o) { x -= o.x; y -= o.y; return *this; }
    Vecll operator-(const Vecll &o) const { return Vecll(*this) -= o; }
    // cross>0 means *this->v is counterclockwise.
    long long cross(const Vecll &o) const { return x*o.y - y*o.x; }
    long long dot(const Vecll &o) const { return x*o.x + y*o.y; }
    long long norm2() const { return x*x + y*y; }
    double norm() const {return sqrt(norm2()); }
    Vecll rot90(bool counterclockwise=true) { 
        if(counterclockwise) return Vecll(-y, x);
        else return Vecll(y, -x);
    }
    int ort() const { // orthant
        if (x==0 && y==0 ) return 0;
        if (y>0) return x>0 ? 1 : 2;
        else return x>0 ? 4 : 3;
    }
    bool operator<(const Vecll& v) const {
        int o = ort(), vo = v.ort();
        if (o != vo) return o < vo;
        return cross(v) > 0;
    }
};
istream& operator>>(istream& is, Vecll& v) {
    is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const Vecll& v) {
    os<<"("<<v.x<<","<<v.y<<")"; return os;
}
bool overlapping(long long l1, long long r1, long long l2, long long r2) {
    if(l1>r1) swap(l1, r1);
    if(l2>r2) swap(l2, r2);
    long long lmax = max(l1, l2);
    long long rmin = min(r1, r2);
    return lmax <= rmin;
}
// v1-v2 cross v3-v4?
// just point touch -> true
bool crossing(const Vecll &v1, const Vecll &v2, const Vecll &v3, const Vecll &v4) {
    long long c12_13 = (v2-v1).cross(v3-v1), c12_14 = (v2-v1).cross(v4-v1);
    long long c34_31 = (v4-v3).cross(v1-v3), c34_32 = (v4-v3).cross(v2-v3);
    if(c12_13 * c12_14 > 0) return false;
    if(c34_31 * c34_32 > 0) return false;
    if(c12_13==0 && c12_14==0) {  // 4 points on the same line
        // both x & y conditions necessary considering vertical cases
        if(overlapping(v1.x,v2.x,v3.x,v4.x) &&
           overlapping(v1.y,v2.y,v3.y,v4.y)) return true;
        else return false;
    }
    return true;
}

const double eps = 1e-8; // suppose max(x,y) <= 1e6;
struct Vecd {
    double x, y;
    Vecd(double x=0, double y=0): x(x), y(y) {}
    Vecd& operator+=(const Vecd& v) { x += v.x; y += v.y; return *this;}
    Vecd operator+(const Vecd& v) const { return Vecd(*this) += v;}
    Vecd& operator-=(const Vecd& v) { x -= v.x; y -= v.y; return *this;}
    Vecd operator-(const Vecd& v) const { return Vecd(*this) -= v;}
    Vecd& operator*=(double s) { x *= s; y *= s; return *this;}
    Vecd operator*(double s) const { return Vecd(*this) *= s;}
    Vecd& operator/=(double s) { x /= s; y /= s; return *this;}
    Vecd operator/(double s) const { return Vecd(*this) /= s;}
    double dot(const Vecd& v) const { return x*v.x + y*v.y;}
    // cross>0 means *this->v is counterclockwise.
    double cross(const Vecd& v) const { return x*v.y - v.x*y;}
    double norm2() const { return x*x + y*y;}
    double norm() const { return sqrt(norm2());}
    Vecd normalize() const { return *this/norm();}
    Vecd rotate90() const { return Vecd(y, -x);}
    void rotate(double theta) {
        Vecd ret;
        ret.x = cos(theta)*x - sin(theta)*y;
        ret.y = sin(theta)*x + cos(theta)*y;
        *this = ret;
    }
    int ort() const { // orthant
    if (abs(x) < eps && abs(y) < eps) return 0;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
    }
    bool operator<(const Vecd& v) const {
      int o = ort(), vo = v.ort();
      if (o != vo) return o < vo;
      return cross(v) > 0;
    }
};
istream& operator>>(istream& is, Vecd& v) {
    is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const Vecd& v) {
    os<<"("<<v.x<<","<<v.y<<")"; return os;
}

//! n*n matrix
const int MX = 2;  // DEFINE PROPERLY!!
template <typename T>
class Mat {
    Mat pow_recursive(Mat b, long long k) {
        Mat ret(b.n);
        if (k == 0) return ret;
        if (k%2 == 1) ret = b;
        Mat tmp = pow_recursive(b, k/2);
        return ret * tmp * tmp;
    }
public:
    int n; T a[MX][MX];
    // Initialize n*n matrix as unit matrix
    Mat (int n, T *src=nullptr): n(n) {  // src must be a pointer (e.g. Mat(n,*src))
        if(!src) {
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
                if(i==j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        } else {
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
                a[i][j] = src[i*n+j];
            }
        }
    }
    // Define operator*
    Mat operator* (const Mat &rhs) {  // Mat * Mat
        Mat ret(n);
        for (int i=0; i<n; ++i) ret.a[i][i] = 0;  // zero matrix
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
    Mat operator* (const T &x) {  // Mat * scaler
        Mat ret(n);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            ret.a[i][j] = a[i][j]*x;
        }
        return ret;
    }
    Mat inv() {  // only for 2*2 matrix & NOT USE IF det(Mat)==0!!!
        T det = a[0][0]*a[1][1]-a[0][1]*a[1][0];
        assert(abs(det)>=EPS);
        Mat ret(n);
        ret.a[0][0] = a[1][1], ret.a[0][1] = -a[0][1];
        ret.a[1][0] = -a[1][0], ret.a[1][1] = a[0][0];
        ret = ret * (1/det);
        return ret;
    }
    void transpose() {
        for(int i=0; i<n; ++i) for(int j=0; j<i; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
    // power k (A^k)
    Mat pow(long long k) { return pow_recursive(*this, k); }
    void set(int i, int j, T x) { a[i][j] = x; }
    T operator()(int i, int j) { return a[i][j]; }
    void print(string debugname="------") {  // for debug
        #ifdef __DEBUG
        cerr << n << '\n';
        cerr << debugname << ":\n";
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            cerr << a[i][j].val() << (j==n-1? '\n': ' ');
        }
        cerr << "---------" << '\n';
        #endif
    }
};

//! O(ROW * COL^2 / 64?)
const int COL = 64;
using BS = bitset<COL>; // size=COL
using vBS = vector<BS>;
struct XorBase {
    int ROW;
    int rank = 0;
    vBS base;
    XorBase(int n): ROW(n), base(n) {}
    void initialize(vBS _base) { base = _base;} 
    void set_new_row(BS bs) { // BE CAREFUL ABOUT CALCULATION COST
        if(rank==ROW) return;
        base[rank] = bs;
        sweep();  // O(ROW * COL^2 / 64?)
    }
    void sweep() {
        rank = 0;
        for(int j=0; j<COL; ++j) {  // find pivot for column j
            int pi = -1;  // pivot i
            for(int i=rank; i<ROW; ++i) {
                if(!base[i][j]) continue;
                pi = i; break;
            }
            if(pi==-1) continue;  // no pivot at column j

            swap(base[rank], base[pi]);
            // delete all other 1 at column j
            for(int i=0; i<ROW; ++i) {
                if(i==rank) continue;
                if(!base[i][j]) continue;
                base[i] ^= base[rank];
            }
            ++rank;
        }
    }
    vBS get_base() { return base;}
    int get_rank() { return rank;}
    BS get_row(int i) { return base[i]; }
    vector<int> find_pivots() { // ret[idx_col] = idx_row
        vector<int> ret(COL, -1);
        int j = 0;
        for(int i=0; i<rank; ++i) {
            while(j<COL && !base[i][j]) ++j;
            if(j<COL) ret[j] = i;
        }
        return ret;
    }
    bool operator==(const XorBase &o) const {
        if(ROW != o.ROW) return false;
        if(rank != o.rank) return false;
        for(int i=0; i<rank; ++i) {
            if (base[i] != o.base[i]) return false;
        }
        return true;
    }
    void dump() { // for debug
        #ifdef __DEBUG
        for(int i=0; i<ROW; ++i) { cerr << base[i] << endl; }
        #endif
    }
    //! ランクやピボット位置が同じでも基底が違えば作れる行列は異なる事に注意！
    //! eg) [[1,1,0],[0,0,1]] != [[1,0,0],[0,0,1]]
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
