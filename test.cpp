#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pair;
typedef pair<double, double> Paird;
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vp vector<Pair>
#define vpd vector<Paird>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvl vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vvd vector<vector<double>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define vvvb vector<vector<vector<bool>>>
#define vvvd vector<vector<vector<double>>>
#define ql queue<ll>
#define dql deque<ll>
#define pql priority_queue<ll>
#define pqla priority_queue<ll,vl,greater<ll>>
#define mll map<ll, ll>
#define rep(i, N) for (ll i=0; i<(ll)(N); i++)
#define repr(i, N) for (ll i = (ll)(N) - 1; i >= 0; i--)
#define repk(i, k, N) for (ll i = k; i < (ll)(N); i++)
#define rep1(i, N) for (ll i=1; i<(ll)(N+1); i++)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define SIZE(v) (ll)((v).size())
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
const ll INF = 3e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;


vector<pair<long long, long long>> prime_factrization (long long n) {
    // eg) 360 = 1^1 * 2^3 * 3^2 * 5^1;
    // primes = {(1,1), (2,3), (3,2), (5,1)}
    // NOTE: 1^1 is always included!!
    vector<pair<long long, long long>> primes;
    primes.emplace_back(1, 1);
    long long rem = n;
    for (long long k=2; k*k<=n; ++k) {
        long long num = 0;
        while(rem % k == 0) {
            ++num;
            rem /= k;
        }
        if (num > 0) primes.emplace_back(k, num);
    }
    if (rem != 1) primes.emplace_back(rem, 1);
    return primes;
}
// Calculate a^b
// a >= 0, b >= 0
long long spow(long long a, long long b) {
	long long ans = 1;
	while (b > 0) {
		if ((b & 1) == 1) {
			ans = ans * a;
		}
		a = a * a;
		b = (b >> 1);
	}
	return ans;
}

int main () {
    ll K; cin >> K;

    vector<Pair> primes = prime_factrization(K);    

    auto g = [&](ll n, ll k) -> ll {
        ll ret = 0;
        for (ll ki=k; ki<=n; ki*=k) {
            ret += n/ki;
        }
        return ret;
    };

    auto f = [&](ll k, ll v) -> ll {
        ll l = 0, r = spow(k, v);
        while (r - l > 1) {
            ll m = (r + l) / 2;
            if (g(m, k) >= v) r = m;
            else l = m;
        }
        return r;
    };

    ll ans = 1;
    for (auto [k, v]: primes) {
        // if (k == 1) continue;
        ll nkai = f(k, v);
        chmax(ans, nkai);
    }
    cout << ans << endl;
}
