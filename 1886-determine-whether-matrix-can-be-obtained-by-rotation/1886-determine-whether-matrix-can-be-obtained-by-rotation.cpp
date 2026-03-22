class Solution {
public:
    vector<vector<int>> rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                rotated[j][n - 1 - i] = mat[i][j];
        return rotated;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int r = 0; r < 4; r++) {
            if (mat == target) return true;
            mat = rotate90(mat);
        }
        return false;
    }
};