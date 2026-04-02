class Solution {
public:
    long long maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        
       
        const long long NEG_INF = LLONG_MIN / 2;
        vector<vector<array<long long, 3>>> dp(
            m, vector<array<long long, 3>>(n, {NEG_INF, NEG_INF, NEG_INF})
        );
        
       
        dp[0][0][0] = coins[0][0];
       
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; 
        } else {
            dp[0][0][1] = coins[0][0]; 
        }
        dp[0][0][2] = max((long long)coins[0][0], 0LL); 
        dp[0][0][1] = max(dp[0][0][0], 0LL);
        dp[0][0][2] = max(dp[0][0][0], 0LL);
        
        auto collect = [](long long prev, int cell, int k_used, int k_next) -> long long {
            if (prev == LLONG_MIN / 2) return LLONG_MIN / 2;
            
            int neutralizations_used_here = k_next - k_used;
            if (neutralizations_used_here == 0) {
                return prev + cell;
            } else {
                
                return prev + max(cell, 0);
            }
        };
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k <= 2; k++) {
                    long long best = NEG_INF;
                    int val = coins[i][j];
                    
                  
                    if (i > 0) {
                        if (dp[i-1][j][k] != NEG_INF)
                            best = max(best, dp[i-1][j][k] + val);
                        if (k > 0 && dp[i-1][j][k-1] != NEG_INF)
                            best = max(best, dp[i-1][j][k-1] + max(val, 0));
                    }
            
                    if (j > 0) {
                        if (dp[i][j-1][k] != NEG_INF)
                            best = max(best, dp[i][j-1][k] + val);
                       
                        if (k > 0 && dp[i][j-1][k-1] != NEG_INF)
                            best = max(best, dp[i][j-1][k-1] + max(val, 0));
                    }
                    
                    dp[i][j][k] = best;
                }
            }
        }
        
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};