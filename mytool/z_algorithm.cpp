#include <bits/stdc++.h>
using namespace std;

vector<int> z_algo(string s) {
    int n = s.size();
    vector<int> a(n);
    int from = -1, last = -1;

    for (int i = 1; i < n; ++i) {
        int same = 0;
        if (from != -1) {
            same = min(a[i-from], last - i);
            same = max(same, 0);
        }
        while (i + same < n && s[same] == s[i+same]) ++same;
        a[i] = same;
        if(last < i + same) {
            from = i;
            last = i+same;
        }
    }
    a[0] = n;

    return a;
}

int main () {
    string s; cin >> s;
    auto a = z_algo(s);
    for (int x: a) cout << x << ' ';
    cout << endl;
}
