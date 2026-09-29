class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        int maxBal = (m + n - 1) / 2;
    
        vector<vector<vector<char>>> dp(m, vector<vector<char>>(n, vector<char>(maxBal + 2, 0)));

        dp[0][0][1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int d = grid[i][j] == '(' ? 1 : -1;
                for (int b = 0; b <= maxBal; b++) {
                    int nb = b - d;         
                    if (nb < 0 || nb > maxBal) continue;
                    bool ok = false;
                    if (i > 0 && dp[i-1][j][nb]) ok = true;
                    if (j > 0 && dp[i][j-1][nb]) ok = true;
                    if (ok) dp[i][j][b] = 1;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};