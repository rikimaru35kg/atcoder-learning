#include <bits/stdc++.h>
using namespace std;

//! Rotate p1 by 90 degrees based on p0.
pair<long,long> rot90(pair<long,long> p1, pair<long,long> p0, bool counter_clockwise=true) {
    auto [x0, y0] = p0;
    auto [x1, y1] = p1;
    long long sign = (counter_clockwise ? 1: -1);
    long long x2 = -sign*(y1 - y0) + x0;
    long long y2 = sign*(x1 - x0) + y0;
    return {x2, y2};
}
