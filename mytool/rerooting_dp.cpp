#include <bits/stdc++.h>
using namespace std;

// Rerooting (snuke code + small modification)
// https://youtu.be/zG1L4vYuGrg?t=7092
struct Rerooting {
    struct DP {
        // edit here (necessary data)
        // ll x, t;
         DP() {}  // edit here (initialization)
        // DP(): x(0), t(0) {}
        DP operator+(const DP &a) const {
            DP ret;
            // edit here
            return ret;
        }
        DP goto_root() const {
            DP ret;
            // edit here
            return ret;
        }
    };

    int n;
    vector<vector<int>> to;  // 隣接リスト  
    vector<vector<DP>> dp; // 頂点vから辺iで繋がる頂点からのdp値 
    vector<DP> ans;  // 頂点vからの求めたい値 
    Rerooting(int n) : n(n), to(n), dp(n), ans(n) {}  // constructor
    void addEdge(int a, int b) {
        to[a].push_back(b);
        to[b].push_back(a);
    }
    void init() { dfs(0); bfs(0); }

    DP dfs(int v, int p=-1) {  // 下向きのみ先に計算 
        DP dpSum;  // 下向きdpの合計 
        int deg = to[v].size();
        dp[v].resize(deg);
        for (int i=0; i<deg; ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dp[v][i] = dfs(u, v);  // uからのdpをdp[v][i]として保存（下向き） 
                                   // 頂点uからの値であり、vはまだ含まれていない事に注意 
            dpSum = dpSum + dp[v][i];
        }
        return dpSum.goto_root();  // vを根として見たときのDPに変換してreturn
    }
    void bfs(int v, const DP &dpP=DP(), int p=-1) {  // 全方位 
        int deg = to[v].size();
        for (int i=0; i<deg; ++i) {
            if (to[v][i] == p) dp[v][i] = dpP;  // 親から上向きのdp
        }
        vector<DP> dpSumL(deg+1), dpSumR(deg+1);  // 累積和 
        for (int i=0; i<deg; ++i) dpSumL[i+1] = dpSumL[i] + dp[v][i];
        for (int i=deg-1; i>=0; --i) dpSumR[i] = dpSumR[i+1] + dp[v][i];
        ans[v] = dpSumL[deg].goto_root();  // 全足しして根をvとしたものに変換 

        for (int i=0; i<deg; ++i) {  // 下の頂点に潜るループ 
            int u = to[v][i];
            if (u == p) continue;
            DP d = dpSumL[i] + dpSumR[i+1];  // remove dp[v][i]
            bfs(u, d.goto_root(), v);  // d.goto_root()は、頂点vを根としたときの上側dpの値 
        }
    }
    DP get(int v) {return ans[v];}
    // clip < ***.cppでの文字化け注意! 
};

int main()
{
    return 0;
}