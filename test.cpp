#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

int main() {
    long double a, b, c; cin >> a >> b >> c;

    if (log2(a) < b*log2(c)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
