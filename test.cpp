#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define repr(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (int i = k; i < (int)(n); i++)


int main () {
    ll N; cin >> N;
    string S; cin >> S;

    if (N == 1) {
        cout << "0" << endl;
        return 0;
    }

    ll p = 1, p0 = 0;
    ll cnt = 0;
    char c_init = S.at(p0);
    rep (i, N) {
        while (S.at(p) == c_init && p < N - 1) {
            p++;
        }
        if (p == N-1 && S.at(p) == c_init) break;

        cnt += (N-p)*(p-i);

        c_init = S.at(p);
        p0 = p;
        p = p + 1;
        i = p0 - 1;

        if (p >= N) break;
    }

    cout << cnt << endl;
}