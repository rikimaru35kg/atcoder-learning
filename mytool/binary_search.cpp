#include<bits/stdc++.h>
using namespace std;

long long binary_search (long long ok, long long ng, auto f) {
    while (llabs(ok-ng) > 1) {
        ll l = min(ok, ng), r = max(ok, ng);
        long long m = l + (r-l)/2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}
//! For DOUBLE TYPE, PLEASE CAST THE TYPE OF INPUTS TO DOUBLE
//! TO CORRECTLY INFER THE PROPER FUNCTION!!
double binary_search (double ok, double ng, auto f) {
    const int REPEAT = 100;
    for(int i=0; i<=REPEAT; ++i) {
        double m = (ok + ng) / 2;
        if (f(m)) ok = m;
        else ng = m;
    }
    return ok;
}