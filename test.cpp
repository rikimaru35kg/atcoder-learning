#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<55;

int main() {
    int N, Q;
    cin >> N;

    vector<vector<long long>> joig(4);
    for (int i = 0; i < N; i++) {
        long long x;
        char c;
        cin >> x >> c;
        if (c == 'J') joig[0].push_back(x);
        else if (c == 'O') joig[1].push_back(x);
        else if (c == 'I') joig[2].push_back(x);
        else joig[3].push_back(x);
    }
    for (int i = 0; i < 4; i++) {
        joig[i].push_back(-INF-i), joig[i].push_back(INF+i);
        sort(joig[i].begin(), joig[i].end());
    }

    cin >> Q;
    while (Q--) {
        long long s, t;
        cin >> s >> t;
        long long res = INF;
        for (int bit = 0; bit < (1 << 4); ++bit) {
            long long tmp = 0, cur = s;
            for (int i = 0; i < 4; ++i) {
                int it = lower_bound(joig[i].begin(), joig[i].end(), cur) - joig[i].begin();
                if (bit & (1 << i)) {
                    // left
                    tmp += abs(cur - joig[i][it - 1]);
                    cur = joig[i][it - 1];
                } else {
                    // right
                    tmp += abs(cur - joig[i][it]);
                    cur = joig[i][it];
                }
            }
            tmp += abs(cur - t);
            res = min(res, tmp);
        }
        cout << res << '\n';
    }
}
