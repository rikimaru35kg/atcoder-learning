#include<bits/stdc++.h>
using namespace std;

struct HeadK {
    long long K, sum = 0;
    bool ascending;
    HeadK (long long K, bool ascending=true): K(K), ascending(ascending) {}
    multiset<long long> stK, stM;
    void add(long long x) {
        if(!ascending) x = -x;
        stK.insert(x);
        sum += x;
        KtoM();
    };
    void del(long long x) {
        if(!ascending) x = -x;
        if (stM.contains(x)) {
            stM.erase(stM.find(x));
        } else {
            if (!stK.contains(x)) return;
            stK.erase(stK.find(x));
            sum -= x;
            while ((long long)stK.size()<K && stM.size()) {
                auto it = stM.begin();
                long long mn = *it;
                stM.erase(it);
                stK.insert(mn);
                sum += mn;
            }
        }
    }
    void decK(long long nk) { // decrease K size
        K = nk;
        KtoM();
    }
    void KtoM() {
        while ((long long)stK.size()>K) {
            auto it = stK.end(); --it;
            long long mx = *it;
            stK.erase(it);
            sum -= mx;
            stM.insert(mx);
        }
    }
    long long get_sum() {
        if(ascending) return sum;
        else return -sum;
    }
};