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
int count(string &s, string t) {
    int ret = 0;
    for(int i=0; i<int(s.size()); ) {
        if(s.substr(i,t.size()) == t) ++ret, i+=t.size();
        else ++i;
    }
    return ret;
}
int count(string &s, char c) { return count(s, string(1,c)); }
int count(vector<string> &s, string t) {
    int ret = 0;
    for(auto &cs: s) ret += count(cs, t);
    return ret;
}
int count(vector<string> &s, char c) { return count(s, string(1,c)); }

//! Judge if t is subsequence of s.
//! If ret==t.size(), then t is subsequence of s.
int subsequence(string &s, string &t) {
    int sn = s.size(), tn = t.size();
    int ti = 0;
    // s can be skipping, t must be contiguous.
    for(int si=0; si<sn && ti<tn; ++si) {
        if(s[si]==t[ti]) ++ti;
    }
    return ti;
}
template<typename T>
int subsequence(vector<T> &s, vector<T> &t) {
    int sn = s.size(), tn = t.size();
    int ti = 0;
    for(int si=0; si<sn && ti<tn; ++si) {
        if(s[si]==t[ti]) ++ti;
    }
    return ti;
}

vector<vector<int>> make_next(string &s, char base='a') {
    int n = s.size(), Z = 26;
    vector<vector<int>> next(Z, vector<int>(n, n));
    for(int i=0; i<n; ++i) next[s[i]-base][i] = i;
    for(int z=0; z<Z; ++z) for(int i=n-2; i>=0; --i) {
        next[z][i] = min(next[z][i], next[z][i+1]);
    }
    return next;
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
