#include <bits/stdc++.h>
using namespace std;

// get max for lines(ai*x+bi)
class ConvexHullTrick {
    struct Line {
        long long a, b;
        Line(long long a, long long b): a(a), b(b) {}
    };
    deque<Line> lines;
    long long fx(Line l, long long x) { return l.a*x + l.b; }
public:
    ConvexHullTrick() {}
    void add(long long a3, long long b3) {
        // (a3,b3) must be input in the asceinding order!
        while((int)lines.size()>=2) {
            auto [a1,b1] = lines.end()[-2];
            auto [a2,b2] = lines.end()[-1];
            if((b1-b2)*(a3-a2)<(a2-a1)*(b2-b3)) break;
            lines.pop_back();
        }
        lines.emplace_back(a3,b3);
    }
    long long get(long long x) {
        //! O(Q*log(N,3))
        int l=0, r=lines.size()-1;
        while(r-l>2) {
            int m1 = (l*2+r)/3;
            int m2 = (l+2*r)/3;
            if(fx(lines[m1],x)<fx(lines[m2],x)) l=m1;
            else r = m2;
        }
        long long ret = fx(lines[l],x);
        for(int i=l+1; i<=r; ++i) ret = max(ret, fx(lines[i],x));
        return ret;
    }
    long long get_in_the_ascending_order(long long x) {
        //! O(N+Q) and irrevirsible
        long long ret = fx(lines[0], x);
        while((int)lines.size()>=2) {
            long long nxt = fx(lines[1], x);
            if(nxt<ret) break;
            ret = nxt;
            lines.pop_front();
        }
        return ret;
    }
};