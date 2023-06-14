#include <bits/stdc++.h>
using namespace std;
using Grid = vector<vector<char>>;

int bfs(int H, int W, const Grid &grid, const pair<int, int> &start,
        const pair<int, int> goal)
{
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    dist.at(start.first).at(start.second) = 0;
    que.push(start);
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    bool arrived = false;
    while (!arrived && !que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        int dist_xy = dist.at(x).at(y);
        for (int i = 0; i < 4; ++i) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if (x2 < 0 || H <= x2 || y2 < 0 || W <= y2)
                continue;
            if (grid.at(x2).at(y2) == 'X')
                continue;
            if (dist.at(x2).at(y2) != -1)
                continue;
            dist.at(x2).at(y2) = dist_xy + 1;
            que.push({x2, y2});
            if (x2 == goal.first && y2 == goal.second) {
                arrived = true;
                break;
            }
        }
    }
    return dist.at(goal.first).at(goal.second);
}

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    Grid grid(H, vector<char>(W));
    vector<pair<int, int>> route(N + 1);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;
            grid.at(i).at(j) = c;
            if (c == 'S')
                route.at(0) = {i, j};
            int k = c - '0';
            if (1 <= k && k <= N)
                route.at(k) = {i, j};
        }
    }
    int sum_dist = 0;
    for (int i = 0; i < N; ++i)
        sum_dist += bfs(H, W, grid, route.at(i), route.at(i + 1));
    cout << sum_dist << endl;
}
