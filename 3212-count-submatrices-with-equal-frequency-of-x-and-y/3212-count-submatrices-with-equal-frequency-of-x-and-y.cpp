class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<array<int,2>>> pre(m, vector<array<int,2>>(n, {0,0}));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = (grid[i][j] == 'X') ? 1 : 0;
                int y = (grid[i][j] == 'Y') ? 1 : 0;
                if (i > 0) { x += pre[i-1][j][0]; y += pre[i-1][j][1]; }
                if (j > 0) { x += pre[i][j-1][0]; y += pre[i][j-1][1]; }
                if (i > 0 && j > 0) { x -= pre[i-1][j-1][0]; y -= pre[i-1][j-1][1]; }
                pre[i][j] = {x, y};
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pre[i][j][0] > 0 && pre[i][j][0] == pre[i][j][1])
                    ans++;
        return ans;
    }
};