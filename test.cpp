#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

int main() {
    int N; cin >> N;

    vector<string> S(N);
    map<string, int> registered;
    rep (i, N) {
        cin >> S.at(i);

        if (registered.count(S.at(i)) == 0) {
            cout << i+1 << endl;
            registered[S.at(i)] = 1;
        }

    }

}
