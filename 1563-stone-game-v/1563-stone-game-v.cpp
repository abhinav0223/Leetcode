class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];
        
        auto sum = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // fill by increasing length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;
                for (int k = i; k < j; k++) {
                    int left = sum(i, k);
                    int right = sum(k + 1, j);
                    int candidate;
                    if (left < right) {
                        candidate = dp[i][k] + left;
                    } else if (left > right) {
                        candidate = dp[k + 1][j] + right;
                    } else {
                        candidate = max(dp[i][k], dp[k + 1][j]) + left;
                    }
                    best = max(best, candidate);
                }
                dp[i][j] = best;
            }
        }
        
        return dp[0][n - 1];
    }
};