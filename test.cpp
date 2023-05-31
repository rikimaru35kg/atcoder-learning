#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

vector<int> colors;

void dfs(vector<vector<int>> &edge, int pos, int color) {
    colors.at(pos) = color;

    for (auto x: edge.at(pos)) {
        if (colors.at(x) != -1) continue;
        dfs(edge, x, 1-color);
    }
}

int main() {
    int N; cin >> N;

    colors.assign(N, -1);

    vector<vector<int>> edge(N);
    rep (i, N-1) {
        int a, b; cin >> a >> b; a--; b--;
        edge.at(a).push_back(b);
        edge.at(b).push_back(a);
    }

    dfs(edge, 0, 0);

    int num_color1 = 0;
    rep (i, N) if (colors.at(i) == 1) num_color1++;

    vector<int> answers;
    if (num_color1 < N/2) {
        rep(i, N) {
            if (colors.at(i) == 0) {
                answers.push_back(i+1);
            }
        }
    }
    else {
        rep(i, N) {
            if (colors.at(i) == 1) {
                answers.push_back(i+1);
            }
        }
    }

    rep (i, answers.size()) {
        if (i < N/2 - 1) cout << answers.at(i) << " ";
        else {
            cout << answers.at(i) << endl;
            break;
        }
    }

}
