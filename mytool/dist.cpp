#include<bits/stdc++.h>
using namespace std;

//! Calculate Manhattan distance
long long manhattan_dist(pair<long long,long long> p1, pair<long long,long long> p2) {
    long long ret = 0;
    ret += abs(p1.first - p2.first);
    ret += abs(p1.second - p2.second);
    return ret;
}

//! Calculate Euclid distance
//! input type = long long
//! output type = double
double euclid_dist(pair<long long,long long> p1, pair<long long,long long> p2) {
    double ret = 0;
    ret += (p1.first - p2.first) * (p1.first - p2.first);
    ret += (p1.second - p2.second) * (p1.second - p2.second);
    ret = sqrt(ret);
    return ret;
}

//! Calculate Euclid distance
//! input type = double
//! output type = double
double euclid_distd(pair<double,double> p1, pair<double,double> p2) {
    double ret = 0;
    ret += (p1.first - p2.first) * (p1.first - p2.first);
    ret += (p1.second - p2.second) * (p1.second - p2.second);
    ret = sqrt(ret);
    return ret;
}

//! Calculate Euclid distance^2
//! input type = long long
//! output type = long long
long long euclid_dist2(pair<long long,long long> p1, pair<long long,long long> p2) {
    double ret = 0;
    ret += (p1.first - p2.first) * (p1.first - p2.first);
    ret += (p1.second - p2.second) * (p1.second - p2.second);
    return ret;
}

int main () {
    cout << euclid_dist({-1, -2}, {2, 3}) << endl;
    cout << euclid_dist2({-1, -2}, {2, 3}) << endl;
    cout << euclid_distd({-1, -2}, {2, 3}) << endl;
}