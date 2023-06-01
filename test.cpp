#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

int main() {
    int N; cin >> N;

    vector<vector<int>> papers(N, vector<int>(4));
    rep (i, N) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        papers.at(i).at(0) = lx;
        papers.at(i).at(1) = ly;
        papers.at(i).at(2) = rx;
        papers.at(i).at(3) = ry;
    }

    vector<vector<int>> area(1010, vector<int>(1010, 0));

    for (auto x: papers) {
        area.at(x.at(1)).at(x.at(0))++;
        area.at(x.at(3)).at(x.at(0))--;
        area.at(x.at(1)).at(x.at(2))--;
        area.at(x.at(3)).at(x.at(2))++;
    }

    // x direction
    rep (i, 1005) {
        rep (j, 1005) {
            area.at(i).at(j+1) += area.at(i).at(j);
        }
    }
    // y direction
    rep (i, 1005) {
        rep (j, 1005) {
            area.at(i+1).at(j) += area.at(i).at(j);
        }
    }

    map<int, int> ans;
    rep (i, 1000) {
        rep (j, 1000) {
            if (ans.count(area.at(i).at(j)) == 0) ans[area.at(i).at(j)] = 1;
            else ans[area.at(i).at(j)] ++;
        }
    }

    rep(i, N){
        if (ans.count(i+1) == 0) cout << "0" << endl;
        else cout << ans[i+1] << endl;
    }
 

}
