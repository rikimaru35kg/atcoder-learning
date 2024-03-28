#include<bits/stdc++.h>
using namespace std;


// 使ってないのでバグあるかも
// 前方向の追加しか対応していない
struct RollingHash {
    long long hash = 0, n = 0;
    long long size, base, mod, pow, ibase;
    RollingHash (long long size, long long base=37, long long mod=1e9+7)
      : size(size), base(base), mod(mod) {
        pow = modpow(base, size);
        ibase = modpow(base, size-2);
    }
    void forward(char add, char del=0) {
        hash = (hash*base + add) % mod; hash = (hash + mod) % mod;
        ++n; if (n<=size) return;
        n = size;
        hash -= pow*del % mod; hash = (hash + mod) % mod;
    }
    long long modpow(long long a, long long b) {
        if (b==0) return 1;
        a %= mod;
        long long f = modpow(a, b/2);
        if (b%2==0)  return f*f % mod;
        else return f*f%mod * a%mod;
    }
    long long val() {return hash;}
};
