#include<bits/stdc++.h>
using namespace std;

vector<pair<char,long long>> run_length_encoding(string &s) {
    vector<pair<char,long long>> ret;
    char last_char = s[0]+1;
    for (auto c: s) {
        if (c != last_char) ret.emplace_back(c, 1);
        else ++ret.back().second;
        last_char = c;
    }
    return ret;
}

vector<pair<long long,long long>> run_length_encoding(vector<long long> v) {
    vector<pair<long long,long long>> ret;
    long long last_num = v[0]+1;
    for (auto x: v) {
        if (x != last_num) ret.emplace_back(x, 1);
        else ++ret.back().second;
        last_num = x;
    }
    return ret;
}

