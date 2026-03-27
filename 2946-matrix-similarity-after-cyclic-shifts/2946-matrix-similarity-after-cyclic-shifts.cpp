class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            int shift = k % n;
            if (shift == 0) continue;
            
            for (int j = 0; j < n; j++) {
                int originalPos;
                if (i % 2 == 0) {
                
                    originalPos = (j + shift) % n;
                } else {
                   
                    originalPos = (j - shift + n) % n;
                }
                if (mat[i][j] != mat[i][originalPos]) return false;
            }
        }
        return true;
    }
};