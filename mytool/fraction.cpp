#include <bits/stdc++.h>
using namespace std;

//! BE CAREFUL ABOUT OVERFLOWING!
//! repeated usage of +/* leads to overflowing
struct Frac {
    long long p, q;  // p/q: p over q
    Frac(long long a, long long b) {
        if (b == 0) {
            p = 1; q = 0;  // inf
            return;
        }
        long long g = gcd(a, b);
        p = a/g; q = b/g;
        if (q<0) {p=-p; q=-q;}
    }
    Frac operator+(const Frac &rhs) {
        if (q == 0 || rhs.q == 0) return Frac(1, 0);
        return Frac(q*rhs.p + p*rhs.q, q*rhs.q);
    }
    Frac operator*(const Frac &rhs) {
        if (q == 0 || rhs.q == 0) return Frac(1, 0);
        return Frac(p*rhs.p, q*rhs.q);
    }
    bool operator==(const Frac &rhs) {
        if (p==rhs.p && q==rhs.q) return true;
        else return false;
    }
};
