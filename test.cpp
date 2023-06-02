#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

struct State {
    int r, c, dir;
};

bool movable(int r, int c, int dr, int dc, vector<vector<char>> &S) {
    if (r+dr < 0) return false;
    if (r+dr >= S.size()) return false;
    if (c+dc < 0) return false;
    if (c+dc >= S.at(0).size()) return false;

    if (S.at(r+dr).at(c+dc) == '#') {
        return false;
    }
    else if (S.at(r+dr).at(c+dc) == '.') {
        return true;
    }
    else {
        cout << "error!" << endl;
        return false;
    }
}

void chmin(int &a, int b) {
    if (b < a) a = b;
}


int main() {
    int H, W; cin >> H >> W;
    int rs, cs; cin >> rs >> cs; rs--; cs--;
    int rt, ct; cin >> rt >> ct; rt--; ct--;

    vector<vector<char>> S(H, vector<char>(W));
    rep (i, H) {
        rep (j, W) {
            cin >> S.at(i).at(j);
        }
    }

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    const int INF = 1 << 30;
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(4, INF)));
    //ue, migi, shita, hidari
    deque<State> que_save;
    rep (i, 4) {
        dist.at(rs).at(cs).at(i) = 0;
        que_save.push_front({rs, cs, i});
    }

    while (!que_save.empty()) {
        State s = que_save.front();
        int r = s.r, c = s.c, dir = s.dir; 
        que_save.pop_front();

        rep (i, 4) {
            int r_n = r + dr.at(i), c_n = c + dc.at(i);
            if (movable(r, c, dr.at(i), dc.at(i), S)) {
                if (i == dir) {
                    if (dist.at(r_n).at(c_n).at(i) > dist.at(r).at(c).at(dir)) {
                        chmin(dist.at(r_n).at(c_n).at(i), dist.at(r).at(c).at(dir));
                        que_save.push_front({r_n, c_n, i});
                    }
                }
                else {
                    if (dist.at(r_n).at(c_n).at(i) > dist.at(r).at(c).at(dir) + 1) {
                        chmin(dist.at(r_n).at(c_n).at(i), dist.at(r).at(c).at(dir) + 1);
                        que_save.push_back({r_n, c_n, i});
                    }
                }
            }
        }
    }

    int ans = INF;
    rep (i, 4) {
        chmin(ans, dist.at(rt).at(ct).at(i));
    }
    cout << ans << endl;

}