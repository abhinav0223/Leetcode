
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> distinct;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distinct.insert(grid[i][j]);

                for (int r = 1; i - r >= 0 && i + r < m && j - r >= 0 && j + r < n; r++) {
                    int sum = 0;

                    for (int k = 0; k < r; k++)
                        sum += grid[i - r + k][j + k];
                    for (int k = 0; k < r; k++)
                        sum += grid[i + k][j + r - k];
                    for (int k = 0; k < r; k++)
                        sum += grid[i + r - k][j - k];

                    for (int k = 0; k < r; k++)
                        sum += grid[i - k][j - r + k];

                    distinct.insert(sum);
                }
            }
        }

        vector<int> result;
        for (auto it = distinct.rbegin(); it != distinct.rend() && result.size() < 3; ++it)
            result.push_back(*it);

        return result;
    }
};