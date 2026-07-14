class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int M = 0;
        for (int x : nums) M = max(M, x);
        
        int size = M + 1; 
        vector<vector<long long>> dp(size, vector<long long>(size, 0));
        dp[0][0] = 1;
        
        auto gcdFunc = [](int a, int b) {
            while (b) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
        };
        
        for (int x : nums) {
            vector<vector<long long>> ndp(size, vector<long long>(size, 0));
            for (int g1 = 0; g1 < size; g1++) {
                for (int g2 = 0; g2 < size; g2++) {
                    long long cnt = dp[g1][g2];
                    if (cnt == 0) continue;
                    
                    ndp[g1][g2] = (ndp[g1][g2] + cnt) % MOD;
                    
                    int ng1 = (g1 == 0) ? x : gcdFunc(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + cnt) % MOD;
                    
                    
                    int ng2 = (g2 == 0) ? x : gcdFunc(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + cnt) % MOD;
                }
            }
            dp = ndp;
        }
        
        long long ans = 0;
        for (int g = 1; g < size; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return (int)ans;
    }
};