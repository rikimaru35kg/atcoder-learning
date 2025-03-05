#include <bits/stdc++.h>
using namespace std;

long long mersenne(long long mn, long long mx) {
    static mt19937_64 mt64(0);
    uniform_int_distribution<long long> get(mn, mx);
    return get(mt64);
}
vector<long long> make_rands(long long mn, long long mx, int n) {
    unordered_set<long long> st;
    while(int(st.size())<n) st.insert(mersenne(mn,mx));
    return vector<long long>(st.begin(), st.end());
}