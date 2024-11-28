#include <bits/stdc++.h>
using namespace std;

//! Crop the rectangle that completely surrounds the specified
//! character c.
//! The rectangle just fits the character c area.
//! (= The rectangle is selected so that the size is minimum.)
vector<string> crop(vector<string> &field, char c='#') {
    long long h = field.size();
    long long w = field[0].size();
    long long i_min = h, i_max = -1;
    long long j_min = w, j_max = -1;
    for(long long i=0; i<h; ++i) {
        for(long long j=0; j<w; ++j) {
            if (field[i][j] == c) {
                i_min = min(i_min, i); i_max = max(i_max, i);
                j_min = min(j_min, j); j_max = max(j_max, j);
            }
        }
    }
    vector<string> ret;
    for(long long i=i_min; i<=i_max; ++i) {
        ret.push_back(field[i].substr(j_min, j_max-j_min+1));
    }
    return ret;
}

//! Delete rows and columns that only include character c.
vector<string> crop_out(vector<string> &field, char c='.') {
    long long h = field.size();
    long long w = field[0].size();
    vector<bool> rows(h), cols(w); 
    for(long long i=0; i<h; ++i) {
        for(long long j=0; j<w; ++j) {
            if (field[i][j] != c) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    vector<string> ret;
    for(long long i=0; i<h; ++i) {
        if (!rows[i]) continue;
        ret.push_back("");
        for(long long j=0; j<w; ++j) {
            if (cols[j]) ret.back() += field[i][j];
        }
    }
    return ret;
}

//! Rotate field by +/-90deg
vector<string> rot90(vector<string> &field, bool clockwise=true) {
    long long h = field.size();
    long long w = field[0].size();
    vector<string> ret(w, string(h, ' '));
    for (long long i=0; i<h; ++i) {
        for (long long j=0; j<w; ++j) {
            if (clockwise) ret[j][h-1-i] = field[i][j];
            else ret[w-1-j][i] = field[i][j];
        }
    }
    return ret;
}

vector<string> transpose(vector<string> &s) {
    long long h = s.size(), w = s[0].size();
    vector<string> ret(w, string(h, '.'));
    for(long long i=0; i<h; ++i) for(long long j=0; j<w; ++j) {
        ret[j][i] = s[i][j];
    }
    return ret;
}
template <typename T>
vector<vector<T>> transpose(vector<vector<T>> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<T>> ret(w, vector<T>(h));
    for(int i=0; i<h; ++i) for(int j=0; j<w; ++j) {
        ret[j][i] = a[i][j];
    }
    return ret;
}

int main () {
    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; ++i) cin >> s[i];
    cout << endl;
    for (int r=0; r<4; ++r) {
        vector<string> s2 = rot90(s, false);
        s.clear();
        s = s2;
        int m = s.size();
        for(int i=0; i<m; ++i) cout << s[i] << endl;
        cout << endl;
    }
}

