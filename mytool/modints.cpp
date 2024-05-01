#include<bits/stdc++.h>
using namespace std;

const long long b = 12345;
const long long MX = 3;
const long long ps[MX] = {1000000007, 1000000021, 1000000033};
struct mints {
    long long data[MX];
    mints(long long x=0) { for(int i=0; i<MX; ++i) data[i] = x%ps[i]; }
    mints operator+(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = (data[i]+x.data[i]) % ps[i];
        return x;
    }
    mints &operator+=(mints x) { *this = *this + x; return *this; }
    mints operator+(long long x) const { return *this + mints(x); }
    mints operator-(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = (data[i]-x.data[i]+ps[i]) % ps[i];
        return x;
    }
    mints &operator-=(mints x) { *this = *this - x; return *this; }
    mints operator-(long long x) const { return *this - mints(x); }
    mints operator*(mints x) const {
        for(int i=0; i<MX; ++i) x.data[i] = data[i]*x.data[i]%ps[i];
        return x;
    }
    mints &operator*=(mints x) { *this = *this * x; return *this; }
    mints operator*(long long x) const { return *this * mints(x); }
    mints pow(long long x) const {
        if (x==0) return mints(1);
        mints ret = pow(x/2);
        ret = ret * ret;
        if (x%2==1) ret = ret * *this;
        return ret;
    }
    bool operator<(mints x) const {
        for(int i=0; i<MX; ++i) if (data[i] != x.data[i]) {
            return data[i] < x.data[i];
        }
        return false;
    }
    void print() const {
        for(int i=0; i<MX; ++i) cerr << data[i] << ' ';
        cerr << '\n';
    }
};

long long binary_search (long long ok, long long ng, auto f) {
    while (llabs(ok-ng) > 1) {
        long long m = (ok + ng) / 2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}