class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int rows = m - k + 1;
        int cols = n - k + 1;

        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

               
                set<int> seen;
                for (int r = i; r < i + k; ++r)
                    for (int c = j; c < j + k; ++c)
                        seen.insert(grid[r][c]);

                
                if (seen.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

            
                int minDiff = INT_MAX;
                int prev = *seen.begin();
                auto it = next(seen.begin());

                while (it != seen.end()) {
                    int diff = *it - prev;   
                    minDiff = min(minDiff, diff);
                    if (minDiff == 1) break;
                    prev = *it;
                    ++it;
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};