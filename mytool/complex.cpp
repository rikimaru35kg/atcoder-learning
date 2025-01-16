#include<bits/stdc++.h>
using namespace std;

struct Complex {
    long long a, b;
    Complex(long long a, long long b): a(a), b(b) {}
    Complex operator+(const Complex &o) const { return Complex(a+o.a, b+o.b); }
    Complex& operator+=(const Complex &o) { *this = *this + o; return *this; }
    Complex operator-(const Complex &o) const { return Complex(a-o.a, b-o.b); }
    Complex& operator-=(const Complex &o) { *this = *this - o; return *this; }
    Complex operator*(const Complex &o) const { return Complex(a*o.a-b*o.b, a*o.b+b*o.a); }
    Complex& operator*=(const Complex &o) { *this = *this * o; return *this; }
    bool operator<(const Complex &o) const {
        if(a==o.a) return b<o.b;
        return a<o.a;
    }
    bool operator==(const Complex &o) const { return a==o.a && b==o.b; }
    long long norm2() { return a*a + b*b; }
};
