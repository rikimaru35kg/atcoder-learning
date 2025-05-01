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

vector<int> z_algo(string s) {
    int n = s.size();
    vector<int> a(n);
    int from=-1, last=-1;
    for (int i=1; i<n; ++i) {
        int same=0;  // length of same substring
        // skip duplicated search
        if (from!=-1) same = min(a[i-from], max(last-i, 0));
        // move forward while possible
        while (i+same<n && s[same]==s[i+same]) ++same;
        a[i] = same;
        if(last < i+same) {  // update from & last
            from = i;
            last = i+same;
        }
    }
    a[0] = n;  // substitute ovious value at last
    return a;
}
vector<int> z_algo(vector<int> s) {
    int n = s.size();
    vector<int> a(n);
    int from=-1, last=-1;
    for (int i=1; i<n; ++i) {
        int same = 0;  // length of same substring
        // skip duplicated search
        if (from!=-1) same = min(a[i-from], max(last-i, 0));
        // move forward while possible
        while (i+same<n && s[same]==s[i+same]) ++same;
        a[i] = same;
        if(last < i+same) {  // update from & last
            from = i;
            last = i+same;
        }
    }
    a[0] = n;  // substitute ovious value at last
    return a;
}

template <class mints> struct RollingHash {
    int n;
    long long base;
    vector<mints> rh, bpow;
    RollingHash(string s="", long long base=1234567): base(base) {
        if(s!="") set(s, base);
    };
    void set(string &s, long long _base=1234567) {
        n = s.size(); rh.resize(n+1,0); bpow.resize(n+1, 1);
        base = _base;
        for(int i=0; i<n; ++i) {
            rh[i+1] = rh[i]*base + s[i];
            bpow[i+1] = bpow[i] * base;
        }
    }
    mints get(int l, int r) { // [l,r)
        assert(l<=r);
        return rh[r] - rh[l]*bpow[r-l];
    }
};

class Manacher {
    int n0;  // length of the original string
    vector<int> p;  // palindrome radii of new string(eg. #a#b#c#)
    // [NOTE] p-1 is palindrome length of the original string
    void calc(string &s) {
        int n = s.size(); p.assign(n, 1);
        int l = -1, r = 0;  // boundary of rightmost palindrome
        // [NOTE] rightmost palindrome span is not [l,r] but (l,r)
        for(int i=0; i<n; i++) {
            p[i] = i>=r ? 1: min(r-i, p[l+r-i]);
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]) {
                p[i]++;
            }
            if(i+p[i]>r) l=i-p[i], r=i+p[i];
        }
    }
public:
    Manacher(string &s): n0(s.size()) {
        string t = "#";
        for(auto c: s) t += c, t += '#';
        calc(t);
    }
    bool is_palindrome(int l, int r) {  // [l,r)
        assert(l>=0 && r<=n0 && l<=r);
        if(l==r) return true;
        --r; l = 2*l+1, r = 2*r+1;
        int m = (l+r)/2;
        return p[m] >= r-m+1;
    }
    // return the longest palindrome from center of [l,r)
    // (note: l,r are partition index values)
    int get_length(int l, int r) {
        assert(l>=0 && r<=n0 && l<=r && r-l<=1);
        int m = l==r ? 2*l : 2*l+1;
        return p[m]-1;
    }
    // return one of the longest palindrome among all substrings
    pair<int,int> longest_palindrome() {  // [l,r)
        int n = p.size();
        pair<int,int> mx;
        for(int i=0; i<n; ++i) mx = max(mx, {p[i],i});
        int m = mx.second;
        int l = (m-(p[m]-2)-1)/2, r = (m+(p[m]-2)-1)/2+1;
        return {l,r};
    }
};

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
