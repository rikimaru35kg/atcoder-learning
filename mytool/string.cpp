#include <bits/stdc++.h>
using namespace std;

string instr() {
    string ret;
    getline(cin, ret);
    if(ret.back()<=31 || ret.back()>=127) ret.pop_back();
    return ret;
}

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

//! count the # of t in s.  O(|S||T|)
long long count(string &s, string t) {
    long long ret = 0;
    long long i=0;
    while(i<(long long)s.size()) {
        if(s.substr(i,t.size()) == t) ++ret, i+=t.size();
        else ++i;
    }
    return ret;
}
long long count(vector<string> &s, string t) {
    long long ret = 0;
    for(long long i=0; i<(long long)s.size(); ++i) {
        ret += count(s[i], t);
    }
    return ret;
}

//! Judge if t is subsequence of s.
//! If ret==t.size(), then t is subsequence of s.
long long subsequence(string &s, string &t) {
    long long sn = s.size(), tn = t.size();
    long long ti = 0;
    for(long long si=0; si<sn && ti<tn; ++si) {
        if(s[si]==t[ti]) ++ti;
    }
    return ti;
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
