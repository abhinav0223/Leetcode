class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1] 
                            + pref[i-1][j] 
                            + pref[i][j-1] 
                            - pref[i-1][j-1];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2) {

            r1++; c1++; r2++; c2++;
            return pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        };

        auto possible = [&](int k) {
            for (int i = 0; i + k - 1 < m; i++) {
                for (int j = 0; j + k - 1 < n; j++) {
                    int sum = getSum(i, j, i + k - 1, j + k - 1);
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(mid)) {
                ans = mid;
                lo = mid + 1;  
            } else {
                hi = mid - 1;  
            }
        }

        return ans;
    }
};
