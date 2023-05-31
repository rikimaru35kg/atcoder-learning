#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

pair<bool, int> num_coins(int r, int &A, int &B, int &C) {
    pair<bool, int> p;
    if (r == 0) {
        p = {true, 0};
        return p;
    }

    if (r >= C){
        p = num_coins(r-C, A, B, C);
        if (p.first) {
            p.second += 1;
            return p;
        }
    }
    if (r >= B){
        p = num_coins(r-B, A, B, C);
        if (p.first) {
            p.second += 1;
            return p;
        }
    }
    if (r >= A){
        p = num_coins(r-A, A, B, C);
        if (p.first) {
            p.second += 1;
            return p;
        }
    }

    p = {false, 0};
    return p;
}

int main() {
    int N; cin >> N;
    int A, B, C; cin >> A >> B >> C;

    int a, b, c;
    c = max(max(A, B), C);
    a = min(min(A, B), C);
    b = (A+B+C) - (a+c);
    A = a; B = b; C = c;

    pair<bool, int> p;
    p = num_coins(N, A, B, C);
    cout << p.second << endl;

}
