class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int m = robot.size();
        int n = factory.size();
        const long long INF = 1e18;
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INF));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;

        for (int j = 1; j <= n; j++) {
            int fpos  = factory[j-1][0];
            int flimit = factory[j-1][1];

            for (int i = 0; i <= m; i++) {
                dp[i][j] = dp[i][j-1];

               
                long long cost = 0;
                for (int k = 1; k <= min(i, flimit); k++) {
                    cost += abs((long long)robot[i-k] - fpos);

                    if (dp[i-k][j-1] != INF)
                        dp[i][j] = min(dp[i][j], dp[i-k][j-1] + cost);
                }
            }
        }

        return dp[m][n];
    }
};