#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

int64_t nCr(int64_t n, int64_t r) {
    int64_t num = 1, den = 1;
    rep (i, r) {
        num *= (n - i);
        den *= (r - i);
        int gc = gcd(num, den);
        num /= gc;
        den /= gc;
    }

    return num/den;
}

int main() {
    int64_t K; cin >> K;
    vector<int64_t> a_k(1000000, 0);

    const int64_t p = 1000000007;

    if (K % 9 != 0) {
        cout << "0" << endl;
        return 0;
    }

    a_k.at(0) = 0;
    rep (i, K+1) {
        if (i == 0) {a_k.at(i) = 1; continue;}
        if (i == 1) {a_k.at(i) = 1; continue;}
        if (i == 2) {a_k.at(i) = 2;continue;}
        if (i == 3) {a_k.at(i) = 4;continue;}
        if (i == 4) {a_k.at(i) = 8;continue;}
        if (i == 5) {a_k.at(i) = 16;continue;}
        if (i == 6) {a_k.at(i) = 32;continue;}
        if (i == 7) {a_k.at(i) = 64;continue;}
        if (i == 8) {a_k.at(i) = 128;continue;}
        rep (j, 9) {
            a_k.at(i) += a_k.at(i-j-1);
            if (a_k.at(i) >= p) a_k.at(i) -= p;
        }
    }

    cout << a_k.at(K) << endl;
}