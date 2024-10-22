#include <bits/stdc++.h>
using namespace std;

tuple<long long,long long,long long> get_line(pair<long long,long long> p1, pair<long long,long long> p2) {
    if(p1==p2) assert(0&&"[Error] get_line() same point for p1 & p2");
    auto [x1,y1] = p1; auto [x2,y2] = p2;
    long long a = 0, b = 0, c = 0;
    a = y2-y1, b = -(x2-x1), c = -x1*y2+y1*x2;
    long long g = gcd(gcd(a,b),c);
    a /= g, b /= g, c /= g;
    if(a==0 && b<0) b=-b, c=-c;
    if(a<0) a=-a, b=-b, c=-c;
    return {a,b,c};
}
