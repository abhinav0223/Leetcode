class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        vector<vector<int>> grid(row, vector<int>(col, 0));

        auto canCross = [&](int day) {
            vector<vector<int>> g(row, vector<int>(col, 0));
            for (int i = 0; i < day; i++) {
                g[cells[i][0] - 1][cells[i][1] - 1] = 1;   // mark flooded
            }

            queue<pair<int,int>> q;
            vector<vector<int>> vis(row, vector<int>(col, 0));

            for (int j = 0; j < col; j++) {
                if (g[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = 1;
                }
            }

            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x == row - 1) return true; // reached bottom

                for (auto& d: dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && ny >= 0 && nx < row && ny < col && !vis[nx][ny] && g[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canCross(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
