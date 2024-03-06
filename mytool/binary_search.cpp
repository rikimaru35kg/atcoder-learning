#include<bits/stdc++.h>
using namespace std;

long long binary_search (long long ok, long long ng, auto f) {
    while (llabs(ok-ng) > 1) {
        long long m = (ok + ng) / 2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}
