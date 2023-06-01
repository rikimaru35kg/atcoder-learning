#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

int INF = 1 << 30;
int N;
vector<vector<int>> A;


int main() {
    cin >> N;

    A.resize(N, vector<int>(N));
    rep (i, N) {
        rep (j, N) {
            cin >> A.at(i).at(j);
        }
    }

    vector<vector<bool>> edge(N, vector<bool>(N, true));
    int M; cin >> M;
    rep (i, M) {
        // decrement
        int x, y; cin >> x >> y; x--; y--;
        edge.at(x).at(y) = false;
        edge.at(y).at(x) = false;
    }

    vector<int> perm;
    rep(i, N) perm.push_back(i);

    int _min = INF;
    do {
        bool kenaku = false;
        rep (i, N-1) {
            if (edge.at(perm.at(i)).at(perm.at(i+1)) == false){
                kenaku = true;
                break;
            }
        }
        if (!kenaku) {
            int sum = 0;
            rep (i, N) sum += A.at(perm.at(i)).at(i);
            if (sum < _min) {
                _min = sum;
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));

    if (_min == INF) cout << "-1" << endl;
    else cout << _min << endl;

}
