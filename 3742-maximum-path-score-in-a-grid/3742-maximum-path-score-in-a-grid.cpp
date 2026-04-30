class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    int cur = dp[i][j][c];

                    if (j + 1 < n) {
                        int nc = c + min(grid[i][j+1], 1);
                        if (nc <= k)
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], cur + grid[i][j+1]);
                    }

                    if (i + 1 < m) {
                        int nc = c + min(grid[i+1][j], 1);
                        if (nc <= k)
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], cur + grid[i+1][j]);
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++)
            ans = max(ans, dp[m-1][n-1][c]);
        return ans;
    }
};
