class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if (m > 1) {
            vector<long long> rowSum(m, 0);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    rowSum[i] += grid[i][j];
            
            long long prefix = 0, total = 0;
            for (long long s : rowSum) total += s;
            
            for (int i = 0; i < m - 1; i++) {
                prefix += rowSum[i];
                if (prefix == total - prefix) return true;
            }
        }
        

        if (n > 1) {
            vector<long long> colSum(n, 0);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    colSum[j] += grid[i][j];
            
            long long prefix = 0, total = 0;
            for (long long s : colSum) total += s;
            
            for (int j = 0; j < n - 1; j++) {
                prefix += colSum[j];
                if (prefix == total - prefix) return true;
            }
        }
        
        return false;
    }
};