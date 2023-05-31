#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i=0; i<(int)(N); i++)
#define rep2(i, A, B) for (int i=(int)(A); i < (int)(B); i++)

#define PI 3.141592653589793

int main() {
    double T, L, X, Y; cin >> T >> L >> X >> Y;
    int Q; cin >> Q;

    vector<double> E(Q);
    rep (i, Q) {
        cin >> E.at(i);
    }

    rep (i, Q) {
        double y, z, theta;
        y = -L/2 * sin(2*PI*E.at(i)/T);
        z = L/2 * (1 - cos(2*PI*E.at(i)/T));

        double a;
        a = sqrt(X*X + (Y-y)*(Y-y));
        theta = abs(atan(z/a) * 180.0 / PI);

        cout << fixed << setprecision(15) << theta << endl;

    }

}
