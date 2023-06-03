#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int main() {
    ll N, K; cin >> N >> K;
    vl A(N), B(N);
    rep (i, N) {
        ll a, b; cin >> a >> b;
        A.at(i) = a;
        B.at(i) = b;
    }

    vl C(N);
    rep (i, N) C.at(i) = A.at(i) - B.at(i);

    vl D(2*N);
    rep (i, N) {
        D.at(i) = B.at(i);
        D.at(i+N) = C.at(i);
    }

    sort(D.begin(), D.end(), greater<ll>());

    ll sum = 0;
    rep (i, K) sum += D.at(i);

    cout << sum << endl;

}
