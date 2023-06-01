#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

#define EPS 0.1

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


int main() {
    int64_t A, B; cin >> A >> B;

    int64_t _gcd = gcd(A, B);

    double ans = (double)(A / _gcd) * (double)B;
    ans = floor(ans+0.3);
    if (ans > floor(pow(10, 18)+0.3)) cout << "Large" << endl;
    else cout << (A / _gcd) * B << endl;

}