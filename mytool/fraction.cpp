#include <bits/stdc++.h>
using namespace std;

//! BE CAREFUL ABOUT OVERFLOWING!
//! repeated usage of +-*/ leads to overflowing
//! Do not repeat +-*/ more than one time (suppose p,q<=|1e9|)
//! BE CAREFUL ABOUT CALCULATION COST!
//! O(logM) just for initializing
struct Frac {
    long long p, q;  // p/q: p over q (like y/x: y over x)
    Frac(long long a=0, long long b=1) {
        if (b==0) {
            p = 1; q = 0;  // inf (no definition of -inf)
            return;
        }
        long long g = gcd(a, b);
        p = a/g; q = b/g;
        if (q<0) {p=-p; q=-q;}
    }
    Frac operator+(const ll x) {
        if (q==0) return Frac(1, 0);
        return *this + Frac(x);
    }
    Frac operator+(const Frac &rhs) {
        if (q==0 || rhs.q==0) return Frac(1, 0);
        return Frac(p*rhs.q + q*rhs.p, q*rhs.q);
    }
    Frac operator-(const ll x) {
        if (q==0) return Frac(1, 0);
        return *this - Frac(x);
    }
    Frac operator-(const Frac &rhs) {
        if (q==0 || rhs.q==0) return Frac(1, 0);
        return Frac(p*rhs.q - q*rhs.p, q*rhs.q);
    }
    Frac operator*(const ll x) {
        if (q==0) return Frac(1, 0);
        return Frac(p*x, q);
    }
    Frac operator*(const Frac &rhs) {
        if (q==0 || rhs.q==0) return Frac(1, 0);
        return Frac(p*rhs.p, q*rhs.q);
    }
    Frac operator/(const ll x) {
        if (q==0 || x==0) return Frac(1, 0);
        return Frac(p, q*x);
    }
    Frac operator/(const Frac &rhs) {
        if (q==0 || rhs.p==0) return Frac(1, 0);
        return Frac(p*rhs.q, q*rhs.p);
    }
    bool operator<(const ll x) const { return *this < Frac(x); }
    bool operator<(const Frac &rhs) const { return p*rhs.q - q*rhs.p < 0; }
    bool operator<=(const ll x) const { return *this <= Frac(x); }
    bool operator<=(const Frac &rhs) const { return p*rhs.q - q*rhs.p <= 0; }
    bool operator>(const ll x) const { return *this > Frac(x); }
    bool operator>(const Frac &rhs) const { return p*rhs.q - q*rhs.p > 0; }
    bool operator>=(const ll x) const { return *this >= Frac(x); }
    bool operator>=(const Frac &rhs) const { return p*rhs.q - q*rhs.p >= 0; }
    bool operator==(const ll x) const { return (q==1 && p==x); }
    bool operator==(const Frac &rhs) { return (p==rhs.p && q==rhs.q); }
};
