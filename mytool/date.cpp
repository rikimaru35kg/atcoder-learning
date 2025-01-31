#include<bits/stdc++.h>
using namespace std;

struct Date {
    int y, m, d;
    vector<int> mon, mon_cum;
    Date(int y, int m, int d): y(y), m(m), d(d), mon(12), mon_cum(13) {
        mon = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=0; i<12; ++i) mon_cum[i+1] = mon_cum[i] + mon[i];
    }
    int total_days() {
        int ret = year_to_day(y-1) + mon_cum[m-1] + d;
        if(is_leap(y) && m>=3) ++ret;
        ret += 6;  // fine adjustment so that Monday = 0
        return ret;
    }
    int weekday() {  // 0:Monday - 6:Sunday
        int ret = total_days() % 7;
        return ret;
    }
    int year_to_day(int y) {
        int ret = y*365; ret += y/4; ret -= y/100; ret += y/400;
        return ret;
    }
    bool is_leap(int y) {
        if(y%400==0) return true;
        if(y%4==0 && y%100!=0) return true;
        return false;
    }
    tuple<int,int,int> get_day() {
        return {y,m,d};
    }
    void inc_day() { // +1day
        if(m==12 && d==31) { ++y, m=1, d=1; return; }
        int lim = mon[m-1];
        if(is_leap(y) && m==2) ++lim;
        if(d==lim) {++m, d=1; return;}
        ++d;
    };
};