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

int main () {
    
}

