#include<bits/stdc++.h>
using namespace std;

const long long MX = 2;
const long long ps[12] = {1000000007, 1000000009, 1000000021,
                          1000000033, 1000000087, 1000000093,
                          1000000097, 1000000103, 1000000123,
                          1000000181, 1000000207, 1000000223};
struct mints {
    long long data[MX];
    mints(long long x=0) { for(int i=0; i<MX; ++i) data[i] = (x+ps[i])%ps[i]; }
    mints operator+(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = (data[i]+x.data[i]) % ps[i];
        return x;
    }
    mints &operator+=(mints x) { *this = *this + x; return *this; }
    mints operator+(long long x) const { return *this + mints(x); }
    friend mints operator+(long long a, mints b) { return mints(a)+b; }
    mints operator-(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = (data[i]-x.data[i]+ps[i]) % ps[i];
        return x;
    }
    mints &operator-=(mints x) { *this = *this - x; return *this; }
    mints operator-(long long x) const { return *this - mints(x); }
    friend mints operator-(long long a, mints b) { return mints(a)-b; }
    mints operator*(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = data[i]*x.data[i]%ps[i];
        return x;
    }
    mints &operator*=(mints x) { *this = *this * x; return *this; }
    mints operator*(long long x) const { return *this * mints(x); }
    friend mints operator*(long long a, mints b) { return mints(a)*b; }
    mints pow(long long x) const {
        if (x==0) return mints(1);
        mints ret = pow(x/2);
        ret = ret * ret;
        if (x%2==1) ret = ret * *this;
        return ret;
    }
    long long pow(long long a, long long b, long long p) const {
        if(b==0) return 1;
        a %= p;
        long long ret = pow(a, b/2, p);
        ret = ret * ret % p;
        if (b%2==1) ret = ret * a % p;
        return ret;
    }
    mints inv() const {
        mints ret;
        for(int i=0; i<MX; ++i) {
            long long p = ps[i];
            long long x = pow(data[i], p-2, p);
            ret.data[i] = x;
        }
        return ret;
    }
    bool operator<(mints x) const {
        for(int i=0; i<MX; ++i) if (data[i] != x.data[i]) {
            return data[i] < x.data[i];
        }
        return false;
    }
    bool operator==(mints x) const {
        for(int i=0; i<MX; ++i) if (data[i] != x.data[i]) return false;
        return true;
    }
    void print() const {
        for(int i=0; i<MX; ++i) cerr << data[i] << ' ';
        cerr << '\n';
    }
};
namespace std {
template<>
struct hash<mints> {
    size_t operator()(const mints &x) const {
        size_t seed = 0;
        for(int i=0; i<MX; ++i) {
            hash<long long> phash;
            seed ^= phash(x.data[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
}
istream& operator>>(istream &is, mints &x) { long long a; cin>>a; x = a; return is; }
ostream& operator<<(ostream& os, mints &x) { os<<x.data[0]; return os; }
using vm = vector<mints>;
using vvm = vector<vector<mints>>;