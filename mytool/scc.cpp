#include <bits/stdc++.h>
using namespace std;

struct SCC {
    SCC (int n): n(n), from(n), ifrom(n) {}
    void add_edge (int a, int b) {
        from[a].push_back(b); ifrom[b].push_back(a);
    }
    vector<vector<int>> scc () {
        vector<vector<int>> groups;
        postorder = vector<int>();
        visited.assign(n, false);
        for (int i=0; i<n; ++i) if(!visited[i]) dfs1(i);
        visited.assign(n, false);
        reverse(all(postorder));
        for(auto v: postorder) if(!visited[v]) {
            vector<int> group;
            dfs2(v, group);
            groups.push_back(group);
        }
        return groups;
    }
private:
    int n;
    vector<vector<int>> from, ifrom;
    vector<int> postorder;
    vector<bool> visited;
    void dfs1 (int v) {
        visited[v] = true;
        for (auto nv: from[v]) if(!visited[nv]) dfs1(nv);
        postorder.push_back(v);
    }
    void dfs2 (int v, vector<int> &group) {
        visited[v] = true;
        group.push_back(v);
        for (auto nv: ifrom[v]) if(!visited[nv]) dfs2(nv, group);
    }
};

int main () {
    int n, m; cin >> n >> m;
    SCC scc(n);
    for(int i=0; i<m; ++i) {
        int a, b; cin >> a >> b;
        scc.add_edge(a, b);
    }
    vector<vector<long long>> groups = scc.scc();
    for(int i=0; i<groups.size(); ++i) {
        for(int j=0; j<groups[i].size(); ++j) {
            cout << groups[i][j] << ' ';
        }
        cout << endl;
    }


}