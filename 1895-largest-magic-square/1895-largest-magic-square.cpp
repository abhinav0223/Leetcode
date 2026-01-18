class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // rowPrefix[i][j+1] = sum of row i from 0..j
        vector<vector<long long>> rowPrefix(m, vector<long long>(n + 1, 0));
        // colPrefix[i+1][j] = sum of col j from 0..i
        vector<vector<long long>> colPrefix(m + 1, vector<long long>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowPrefix[i][j + 1] = rowPrefix[i][j] + grid[i][j];
                colPrefix[i + 1][j] = colPrefix[i][j] + grid[i][j];
            }
        }

        // diag1 prefix for main diagonals (top-left -> bottom-right)
        // d1[i+1][j+1] = sum along diag ending at (i,j)
        vector<vector<long long>> d1(m + 1, vector<long long>(n + 1, 0));
        // diag2 prefix for anti diagonals (top-right -> bottom-left)
        // d2[i+1][j] = sum along anti-diag ending at (i,j)
        vector<vector<long long>> d2(m + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        auto getRowSum = [&](int r, int c1, int c2) -> long long {
            return rowPrefix[r][c2 + 1] - rowPrefix[r][c1];
        };

        auto getColSum = [&](int c, int r1, int r2) -> long long {
            return colPrefix[r2 + 1][c] - colPrefix[r1][c];
        };

        // main diagonal sum in square with top-left (r,c), size k
        auto getDiag1 = [&](int r, int c, int k) -> long long {
            return d1[r + k][c + k] - d1[r][c];
        };

        // anti diagonal sum in square with top-left (r,c), size k
        auto getDiag2 = [&](int r, int c, int k) -> long long {
            // anti diagonal goes from (r, c+k-1) down-left
            return d2[r + k][c] - d2[r][c + k];
        };

        int ans = 1;
        int maxK = min(m, n);

        // Try larger size first (we can break early when found)
        for(int k = maxK; k >= 2; k--) {
            bool found = false;
            for(int i = 0; i + k - 1 < m; i++) {
                for(int j = 0; j + k - 1 < n; j++) {

                    long long target = getRowSum(i, j, j + k - 1);

                    // check all rows
                    bool ok = true;
                    for(int r = i; r < i + k; r++) {
                        if(getRowSum(r, j, j + k - 1) != target) {
                            ok = false; break;
                        }
                    }
                    if(!ok) continue;

                    // check all cols
                    for(int c = j; c < j + k; c++) {
                        if(getColSum(c, i, i + k - 1) != target) {
                            ok = false; break;
                        }
                    }
                    if(!ok) continue;

                    // check both diagonals
                    if(getDiag1(i, j, k) != target) continue;
                    if(getDiag2(i, j, k) != target) continue;

                    found = true;
                    break;
                }
                if(found) break;
            }
            if(found) return k;
        }

        return ans;
    }
};