class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), compare);

        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) {
            endTimes[i] = events[i][1];
        }

       
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int value = events[i - 1][2];

            int l = 0, r = i - 1, prev = 0;
            while (l < r) {
                int m = (l + r) / 2;
                if (endTimes[m] < start)
                    l = m + 1;
                else
                    r = m;
            }
            if (endTimes[l] < start) prev = l + 1;
            else prev = l;

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value);
            }
        }

        return dp[n][k];
    }
};