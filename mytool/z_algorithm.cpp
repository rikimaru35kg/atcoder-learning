#include <bits/stdc++.h>
using namespace std;

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

int main () {
    // string s; cin >> s;
    int n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    auto b = z_algo(a);
    for (int x: b) cout << x << ' ';
    cout << endl;
}
