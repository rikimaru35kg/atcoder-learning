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
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repk(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define all(v) (v).begin(), (v).end()


bool is_ok(ll x, vl &H, vl &S) {
	vl l;
	ll N = H.size();
	rep (i, N) {
		l.push_back((x-H.at(i))/S.at(i));
	}
    sort(all(l));
	rep(j, N) {
		if (l.at(j) < j) {
			return false;
		}
	}
    return true;
}

ll meguru_bisect(ll ng, ll ok, vl &H, vl &S) {
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (is_ok(mid, H, S)) {
            ok = mid;
		}
        else{
            ng = mid;
		}
	}
    return ok;
}

int main() {
    ll N; cin >> N;
    vl H(N), S(N);
    rep (i, N) cin >> H.at(i) >> S.at(i);

	ll tmp = meguru_bisect(0, 1e18, H, S); 
	cout << tmp << endl;
}

