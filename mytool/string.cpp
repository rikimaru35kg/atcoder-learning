#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, char t) {
    vector<string> ret; string now;
    for(auto c: s) {
        if(c==t) {
            if(now.size()) ret.push_back(now);
            now = "";
        } else now += c;
    }
    if(now.size()) ret.push_back(now);
    return ret;
}

//! count the # of t in s
long long count(string s, string t) {
    long long ret = 0;
    while(s.rfind(t)!=string::npos) {
        ++ret;
        s.erase(s.begin()+s.rfind(t), s.end());
    }
    return ret;
}

vector<long long> z_algo(string s) {
    long long n = s.size();
    vector<long long> a(n);
    long long from = -1, last = -1;
    for (long long i = 1; i < n; ++i) {
        long long same = 0;  // length of same substring
        // skip duplicated search
        if (from != -1) same = min(a[i-from], max(last - i, 0LL));
        // move forward while possible
        while (i + same < n && s[same] == s[i+same]) ++same;
        a[i] = same;
        if(last < i + same) {  // update from & last
            from = i;
            last = i+same;
        }
    }
    a[0] = n;  // substitute ovious value at last
    return a;
}

vector<long long> z_algo(vector<long long> s) {
    long long n = s.size();
    vector<long long> a(n);
    long long from = -1, last = -1;
    for (long long i = 1; i < n; ++i) {
        long long same = 0;  // length of same substring
        // skip duplicated search
        if (from != -1) same = min(a[i-from], max(last - i, 0LL));
        // move forward while possible
        while (i + same < n && s[same] == s[i+same]) ++same;
        a[i] = same;
        if(last < i + same) {  // update from & last
            from = i;
            last = i+same;
        }
    }
    a[0] = n;  // substitute ovious value at last
    return a;
}

//! Change 26 to an appropriate number
string excel_string(long long n, char base='A') {
    const long long m = 26;
    string ret;
    while(n) {
        --n;
        ret += n%m + base;
        n /= m;
    }
    reverse(all(ret));
    return ret;
}
long long num_of_excel_string(string s, char base='A') {
    const long long m = 26;
    long long ret = 0;
    for(auto c: s) {
        ret = ret*m + c-base + 1;
    }
    return ret;
}

int main () {
    // string s; cin >> s;
    int n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    auto b = z_algo(a);
    for (int x: b) cout << x << ' ';
    cout << endl;
}
