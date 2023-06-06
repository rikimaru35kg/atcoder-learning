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

ll str2eight(string str_in) {
    ll _tmp = 0;
    ll _pow = str_in.size() - 1;
    for (char x: str_in) {
        ll _tmp2 = int(x) - int('0');
        rep (i, _pow) _tmp2 *= 8;
        _pow--;
        _tmp += _tmp2;
    }
    return _tmp;
}

string eight2str(ll num_in) {
    string _tmp = "";
    while (num_in > 0) {
        string _tmp2 = to_string(num_in % 8);
        _tmp = _tmp2 + _tmp;
        num_in /= 8;
    }

    if (_tmp == "") return "0";
    else return _tmp;
}

ll ch9(ll x) {
    stack<ll> q_num;
    while (x > 0) {
        ll _tmp;
        _tmp = x % 9;
        x /= 9;
        if (_tmp == 8) _tmp = 5;
        q_num.push(_tmp);
    }

    ll num = 0;
    while(!q_num.empty()) {
        ll _tmp;
        _tmp = q_num.top();
        q_num.pop();

        num *= 8;
        num += _tmp;
    }
    return num;
}

int main() {
    string N; cin >> N;
    ll K; cin >> K;

    ll N2 = str2eight(N);
    ll ans = N2;

    rep (i, K) ans = ch9(ans);

    cout << eight2str(ans) << endl;
}
