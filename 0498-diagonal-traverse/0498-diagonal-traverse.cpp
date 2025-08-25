class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> intermediate;
            int r = (d < n) ? 0 : d - n + 1;
            int c = d - r;
            while (r < m && c >= 0) {
                intermediate.push_back(mat[r][c]);
                r++;
                c--;
            }
            if (d % 2 == 0) {
                reverse(intermediate.begin(), intermediate.end());
            }
            result.insert(result.end(), intermediate.begin(), intermediate.end());
        }

        return result;
    }
};