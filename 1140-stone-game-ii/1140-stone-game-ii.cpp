class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                } else {
                    int best = 0;
                    for (int X = 1; X <= 2 * m; X++) {
                        int opponent = dp[i + X][max(m, X)];
                        best = max(best, suffix[i] - opponent);
                    }
                    dp[i][m] = best;
                }
            }
        }

        return dp[0][1];
    }
};