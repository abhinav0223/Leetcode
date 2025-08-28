class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int startRow = 0; startRow < n; ++startRow) {
            vector<int> diag;
            int r = startRow, c = 0;
            while (r < n && c < n) {
                diag.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(diag.begin(), diag.end(), greater<int>());
            r = startRow, c = 0;
            int idx = 0;
            while (r < n && c < n) {
                grid[r][c] = diag[idx++];
                r++;
                c++;
            }
        }
        for (int startCol = 1; startCol < n; ++startCol) {
            vector<int> diag;
            int r = 0, c = startCol;
            while (r < n && c < n) {
                diag.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(diag.begin(), diag.end());
            r = 0, c = startCol;
            int idx = 0;
            while (r < n && c < n) {
                grid[r][c] = diag[idx++];
                r++;
                c++;
            }
        }

        return grid;
    }
};